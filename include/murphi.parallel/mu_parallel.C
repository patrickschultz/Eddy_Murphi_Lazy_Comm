#include <pthread.h>
#include <mpi.h>
#include <string>
#include <iostream>
#include <cassert>
#include "mu_parallel.h"
#include "mu_log.h"

//
// The address of this function is passed as a param on thread creation
// of the communication thread.  'this_p' is the pointer to the
// incarnation of commManager calling for access to non-static member
// functions.
//
void *CommThreadEntry(void* this_p) {
	commManager *p = (commManager *) this_p;
	p->Run_commMgr(NULL);
	return 0;
}

//
// The constructor initializes members with data passed as params,
// initializes MPI, thread constructs (mutexes and a condition signal)
// and sets up logical pointers to the MPI request queue and initializes
// a comm queue for each other member in MPI universe
//
commManager::commManager(void(*Hashstats)(int, unsigned long *, double *,
		bool *), int(*Queue)(char*, int), int(*workWaiting)(),
		unsigned long(*getQueueSize)(), void(*AcceptPullRequest)(int),
		int stateLen, int *argc, char*** argv) :
	StateLen(stateLen) {
	/// This sets the pointers to functions passed by caller
	hashstats = Hashstats; // future use
	queue = Queue;
	this->workWaiting = workWaiting;
	queueSize = getQueueSize; //Patrick
	acceptPullRequest = AcceptPullRequest; //Patrick

	/// Initialize the counters for this rank
	Received = 0;
	Sent = 0;
	Max_states_in_msg = 0;
	Avg_states_in_msg = 0;

	/// Initialize status flags
	workerWaiting = false;
	Terminate = false; // only one thread here, no blocking required

	/// This starts the MPI system and sets the initial time (iTime)
	/// and gets the count of nodes and the rank of this node
	MPI_Init(argc, argv);
	MPI_Barrier(MPI_COMM_WORLD);
	iTime = MPI_Wtime();
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	if (numProcs < 2)
		Error.Notrace("Give at least 2 processors");

	LOG_INIT(myRank);

	/// This initializes the status of the stable condition token
	if (myRank != 0) { //if root, we have token
		scTokenValid = false;
	} else {
		scTokenValid = true;
	}
	// initially, every node is white
	m_nodeColor = WHITE;

	// Init state message reply counts, minus self
	m_stateReplyCount = new short[numProcs];
	for (int i = 0; i < numProcs; i++)
		m_stateReplyCount[i] = 0;

	final_stats_buf1 = NULL;
	final_stats_buf1_d = NULL;
	final_stats_buf2 = NULL;
	final_stats_buf3 = NULL;

	//Patrick
	nodeLoads = new nodeLoad[numProcs];
	for (int i = 0; i < numProcs; i++) {
		nodeLoads[i].loadValue = 0;
	}

	sqrtNumProcs = (int) ceil(sqrt(numProcs));

#ifdef NO_AVAILABLE_BUFFERS_STATS
	no_available_buffers_stats[0] = no_available_buffers_stats[1] = no_available_buffers_stats[2] = 0;
#endif

#ifdef DDISTC
	///this initializes the Owners counts to 0
	InitOwners();
#endif
}

void commManager::DoBarrierAndFinalize() {
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
}

//
// This initializes the communication queues (needs to be called after the
// processing of the command line, which in turn needs MPI to br turned on)
//
void commManager::InitializeCommQueues(int NumBuffs, int BuffSize) {
	this->NumBuffs = NumBuffs;
	this->BuffSize = BuffSize;
	Min_states_in_msg = NumBuffs * BuffSize;
	/// This initializes the MPI request logical stacks (idle and active)
	/// based on the array reqStruct -- it is used to track MPI sends
	/// and release buffers once the transmission is complete
	reqHead = -1;
	idleHead = 0;
	reqArray = new reqStruct[NumBuffs * numProcs];
	for (int x = 0; x < numProcs * NumBuffs; x++) {
		if (x != numProcs * NumBuffs - 1) {
			reqArray[x].next = x + 1;
			continue;
		}
		reqArray[x].next = -1;
	}

	/// This creates and initializes the communication queues, one for each
	/// other node in the MPI world
	queues = new commQueue*[numProcs];
	for (int rank = 0; rank < numProcs; rank++) {
		if (rank == myRank)
			continue;
		queues[rank] = new commQueue(BuffSize, StateLen, AuxLen, NumBuffs);
	}
}

//
// Total amount (in bytes) of memory allocated or to be allocated
//
unsigned long commManager::memory_allocated() {
	int numProcsStats = IsRoot() ? numProcs - 1 : 1;
	return (unsigned long) sizeof(commManager)
			+ (unsigned long) (sizeof(reqStruct) * NumBuffs * numProcs)
			+ (unsigned long) (sizeof(struct final_stats1) * (numProcsStats))
			+ (unsigned long) (sizeof(struct final_stats1_d) * (numProcsStats))
			+ (unsigned long) (sizeof(struct final_stats2) * (numProcsStats))
			+ (unsigned long) (sizeof(struct final_stats3) * (numProcsStats))
			+
#ifdef HASHC
			(args->print_trace.value? (unsigned long)(sizeof(struct final_hashmatrix)*(numProcsStats)) : 0) +
#endif
			(unsigned long) (sizeof(commQueue *) * numProcs)
			+ (unsigned long) (commQueue::memory_allocated(BuffSize, StateLen,
					AuxLen, NumBuffs) * (numProcs - 1));
}

//
// Total amount (in bytes) of memory allocated or to be allocated
//
unsigned long commManager::memory_allocated(int BufSize, int BufCount) {
	int numProcsStats = IsRoot() ? numProcs - 1 : 1;
	return (unsigned long) sizeof(commManager)
			+ (unsigned long) (sizeof(reqStruct) * BufCount * numProcs)
			+ (unsigned long) (sizeof(struct final_stats1) * (numProcsStats))
			+ (unsigned long) (sizeof(struct final_stats1_d) * (numProcsStats))
			+ (unsigned long) (sizeof(struct final_stats2) * (numProcsStats))
			+ (unsigned long) (sizeof(struct final_stats3) * (numProcsStats))
			+ (unsigned long) (sizeof(commQueue *) * numProcs)
			+
#ifdef HASHC
			(args->print_trace.value? (unsigned long)(sizeof(struct final_hashmatrix)*(numProcsStats)) : 0) +
#endif
			(unsigned long) (commQueue::memory_allocated(BufSize, StateLen,
					AuxLen, BufCount) * (numProcs - 1));
}

//
// Starts the comm manager thread
//
void commManager::StartThread() {
	CommThreadEntry(this);
}

//
// deletes all the memory allocated in the constructor and in the final statistics sending
// 
commManager::~commManager() {
	for (int x = 0; x < numProcs; x++)
		if (x != myRank)
			delete queues[x];
	delete[] queues;
	delete[] reqArray;
	delete[] m_stateReplyCount;

	if (final_stats_buf1 != NULL)
		delete[] final_stats_buf1;
	if (final_stats_buf1_d != NULL)
		delete[] final_stats_buf1_d;
	if (final_stats_buf2 != NULL)
		delete[] final_stats_buf2;
	if (final_stats_buf3 != NULL)
		delete[] final_stats_buf3;
#ifdef NO_AVAILABLE_BUFFERS_STATS
	no_available_buffers_stats[0] = no_available_buffers_stats[1] = no_available_buffers_stats[2] = 0;
	mutexes->LockMutex(MUTEX_PRINT);
	std::cout << "Node " << myRank << ", counting no_available_buffers_stats: "
	<< no_available_buffers_stats[0] << " " << no_available_buffers_stats[1] << " " << no_available_buffers_stats[2] << std::endl;
	std::cout.flush();
	mutexes->UnLockMutex(MUTEX_PRINT);
#endif
}

//
// Computation terminated, stop also the other nodes
//
void commManager::BroadcastAndEnd() {
	BroadcastTerminate();
	End();
}

//
// Displays errors with comm Manager or comm queue
//
void commManager::DisplayCQError(std::string location) {
	mutexes->LockMutex(MUTEX_PRINT);
	std::cout << myRank << ", " << MPI_Wtime() - iTime
			<< ", C, Catastrophic failure in: " << location << std::endl;
	std::cout.flush();
	mutexes->UnLockMutex(MUTEX_PRINT);
}

//
// Displays MPI errors, decoding MPI error code
//
void commManager::DisplayMPIError(std::string location, int MPIcode) {
	char errString[MPI_MAX_ERROR_STRING + 1];
	int errLen;
	MPI_Error_string(MPIcode, errString, &errLen);
	errString[errLen] = '\0';
	mutexes->LockMutex(MUTEX_PRINT);
	std::cout << myRank << ", " << MPI_Wtime() - iTime << ", C, MPI Error at: "
			<< location << " with: " << std::string(errString) << std::endl;
	std::cout.flush();
	mutexes->UnLockMutex(MUTEX_PRINT);
}

int commManager::Flush(int owner) {
	int retVal = CATASTROPHIC_FAILURE;

	if (owner < 0 || owner > numProcs)
		return retVal;

	if (owner == myRank)
		return retVal;

	retVal = queues[owner]->Flush();

	LOG_VERBOSE(" (communicate) Flushing sending queues for Node %d.\n" , owner);
	return retVal;
}

//
// Called by the worker thread when a state not owned by the current node is
// reached; instead of immediately sending the state, will attempt to push 
// a state onto the owner's sending line. If there is no available buffer, it
// keeps trying until it succeeds or Terminate is set (yielding the
// communication thread after NO_AVAILABLE_BUFFERS_TRIALS consecutive failures)
// DoSends will eventually perform the MPI_Isend of a whole queue line (so, many
// states are sent at the same time to their owner)
//
int commManager::PushState(char* state, int owner) {
	int retVal = CATASTROPHIC_FAILURE;
	int tryCount = 0, totalTryCount = 0;

	if (owner < 0 || owner > numProcs || state == NULL)
		return retVal;

	if (owner == myRank)
		return retVal;

	// Set the node color to black, meaning that this node has initiated work elsewhere
	m_nodeColor = BLACK;

	retVal = queues[owner]->Push(state, owner);
	++tryCount;
	++totalTryCount;
	while (retVal == NO_AVAILABLE_BUFFERS) {
		mutexes->LockMutex(MUTEX_TERMINATE);
		if (Terminate) {
			mutexes->UnLockMutex(MUTEX_TERMINATE);
			break;
		}
		mutexes->UnLockMutex(MUTEX_TERMINATE);
		if (tryCount >= NO_AVAILABLE_BUFFERS_TRIALS) {
			sched_yield();
			tryCount = 0;
		}
		retVal = queues[owner]->Push(state, owner);
		++tryCount;
		++totalTryCount;
	}
#ifdef NO_AVAILABLE_BUFFERS_STATS
	if (totalTryCount > 0) {
		if (totalTryCount >= 1 || totalTryCount <= 2)
		no_available_buffers_stats[0]++;
		else if (totalTryCount >= 3 && totalTryCount <= 5)
		no_available_buffers_stats[1]++;
		else
		no_available_buffers_stats[2]++;
	}
#endif
	LOG_VERBOSE(" (communicate) Results of pushing state [%d].\n" , retVal);
	return retVal;
}

/**
 * Patrick
 * TODO
 */
void commManager::handleStatePullRequest() {
	int err;
	int requesting_rank;
	MPI_Status stat;

	err = MPI_Recv(&requesting_rank, MESSAGE_REQ_STATES_LENGTH,
			MPI_UNSIGNED_LONG, MPI_ANY_SOURCE, MESSAGE_REQ_STATES,
			MPI_COMM_WORLD, &stat);
	if (err) {
		// MPI error in MPI_Receive()
		DisplayMPIError("handleStatePullRequest(), MPI_Receive()", err);
		BroadcastAndEnd();
		return;
	}

	LOG_VERBOSE(" (communicate) Node %d sent state pull request.\n", requesting_rank);

	unsigned long numElmtsInQueue = queueSize();
	// If we don't have enough to send, we don't and tell the sender we won't
	if (numElmtsInQueue < MINIMUM_QUEUE_FOR_PULL_REQUEST) {
		LOG_VERBOSE(" (communicate) Denying state pull request from node %d. %lu states in queue.\n", requesting_rank, numElmtsInQueue );
		MPI_Request req;
		err = MPI_Isend(&myRank, MESSAGE_REQ_STATES_DENY_REPLY_LENGTH, MPI_INT,
				stat.MPI_SOURCE, MESSAGE_REQ_STATES_DENY_REPLY, MPI_COMM_WORLD,
				&req);
		MPI_Request_free(&req);

		if (err) {
			DisplayMPIError("ReceiveStates(), MPI_Isend()", err);
			BroadcastAndEnd();
			return;
		}
	} else {
		LOG_VERBOSE(" (communicate) Accepting state pull request from node %d. %lu states in queue.\n", requesting_rank, numElmtsInQueue );
		acceptPullRequest(requesting_rank);
	}
}

//
// Called by worker thread if the local consumption queue (i.e. the main
// BFS queue) is empty. Instead of directly terminate the verification, the
// worker thread sleeps till the communication thread awakes it, which may occur
// either because of new states in in the local consumption queue (received from
// some other node, see ReceiveStates) or because of termination set (by some
// other node, see ReceiveTerminate)
//
void commManager::CheckStableCondition() {
	mutexes->LockMutex(MUTEX_WRKR_SLP);
	mutexes->LockMutex(MUTEX_TERMINATE);
	if (!Terminate) {
		mutexes->UnLockMutex(MUTEX_TERMINATE);
		if (workWaiting() == 0) {
			workerWaiting = true;
			LOG_VERBOSE(" (threading) Worker idle, going to sleep.\n");
			mutexes->WaitMutex(SIGNAL_WRKR_SLP);
		}
		// otherwise, in the meanwhile the communication thread was able to fill the
		// local consumption queue again...
	} else
		mutexes->UnLockMutex(MUTEX_TERMINATE);
	mutexes->UnLockMutex(MUTEX_WRKR_SLP);
}

//
// Sends the termination message to each node of MPI universe
// This will occur either upon catastrophic failure, Murphi invariant failure
// or completion (this last one may be determined by root node only)
//
void commManager::BroadcastTerminate() {
	int err;
	MPI_Request req;

	for (int rank = 0; rank < numProcs; rank++) {
		if (rank == myRank)
			continue;
		mutexes->LockMutex(MUTEX_RSLT);
		switch (result) {
		case 'y':
			result_buf[0] = 0;
			break;
		case 'n':
			result_buf[0] = 1;
			break;
		case 'e':
			result_buf[0] = 2;
			break;
		default:
			result_buf[0] = 3;
			break;
		}
		mutexes->UnLockMutex(MUTEX_RSLT);
		result_buf[1] = (unsigned long) myRank;
		result_buf[2] = NumCurState; /* to be used only with -tv... */
		err = MPI_Isend(result_buf, MESSAGE_TERMINATE_ULONG_LENGTH,
				MPI_UNSIGNED_LONG, rank, MESSAGE_TERMINATE, MPI_COMM_WORLD,
				&req);
		if (err)
			DisplayMPIError("BroadcastTerminate(), MPI_Isend()", err);
	}
}

//
// this is for the internal MPI request queue -- returns false if there is 
// no room (idleHead is set to -1). If there is room, a reqStruct is 
// logically popped from idle and put in active (becomming reqHead) 
// and loaded with the values passed in
//
bool commManager::PushReq(MPI_Request req, int node, int buf) {
	if (idleHead == -1)
		return false;

	int temp = reqHead;
	reqHead = idleHead;
	idleHead = reqArray[idleHead].next;
	reqArray[reqHead].next = temp;
	reqArray[reqHead].req = req;
	reqArray[reqHead].node = node;
	reqArray[reqHead].buffer = buf;
	return true;
}

//
// This function will attempt to send all queue lines in each queue
// (one for each other rank in MPI universe) that is waiting to send
//  -- it does not block, but pushes the MPI request onto the local MPI 
// request stack to be checked later by 'RecoverBuffers' if the send was 
// completed Returns true if did any sending.
//
bool commManager::DoSends() {
	// a pointer to a commQueue buffer

	char *buf;
	int len, index, retVal, err = 0;
	bool didWork = false;
	MPI_Request req;

	for (int node = 0; node < numProcs; node++) {
		if (node == myRank)
			continue;
		if (m_stateReplyCount[node] < 0) {
			didWork = true;
			continue;
		}

		// get a buffer waiting to be sent from 'node's queue
		// here (and in the equivalent call below) workerWaiting is used speedup purposes,
		// so never mind if it changes immediately after the call...

		retVal = queues[node]->GetBufferToCopy(&buf, &len, &index,
				workerWaiting);

		// keep sending as long as there are buffers to send in 'node's' commQueue
		//    while (retVal == SUCCESS){
		if (retVal == SUCCESS) {
			// set return from this function showing we worked
			didWork = true;
			err = MPI_Isend(buf, len, MPI_CHAR, node, MESSAGE_STATES,
					MPI_COMM_WORLD, &req);

			// decrement replyCount
			m_stateReplyCount[node]--;

			LOG_VERBOSE(" (communicate) Sending states to node %d (reply count %d)\n", node, m_stateReplyCount[node]);

			if (err) {
				// hits this block if there was an error in the MPI send
				DisplayMPIError("DoSends(), MPI_ISend()", err);
				BroadcastAndEnd();
			}

			++Sent;
			if (len > Max_states_in_msg)
				Max_states_in_msg = len;
			if (len < Min_states_in_msg)
				Min_states_in_msg = len;
			Avg_states_in_msg += len;
			// add MPI send request to the request stack
			assert(PushReq(req, node, index)); //should never fail
			// see if there are more waiting to be sent
			retVal = queues[node]->GetBufferToCopy(&buf, &len, &index,
					workerWaiting);

		} // exit when retVal is not SUCCESS

		// hits this block if the commQueue returned cat failure
		if (retVal == CATASTROPHIC_FAILURE) {
			DisplayCQError("DoSends(), GetBufferToCopy()");
			BroadcastAndEnd();
		}
	} // all nodes handled
	return didWork;
}

//
// Removes 'index' from the request array and
// Pushes 'index' onto the 'idle stack'
//
void commManager::PopReq(int prev, int index) {
	if (index != reqHead) {
		reqArray[prev].next = reqArray[index].next;
	} else {
		reqHead = reqArray[index].next;
	}
	int temp = idleHead;
	idleHead = index;
	reqArray[idleHead].next = temp;
}

//
// Checks all 'active' in reqArray for a completed MPI send -- 
// if successful, pops it from 'active', and the buffer is released (the line
// may be used by other states)
// Goes through request stack from the head down
//
bool commManager::RecoverBuffers(bool &hasPendingSends) {
	int flag = 0, err;
	int index = reqHead, prev = reqHead, next = -1;
	bool retVal = false;
	MPI_Status status;

#ifdef ENABLE_FILE_LOGGING
	int numBuffersUsed = 0;
#endif

	//make sure that we don't index on -1
	if (reqHead != -1) {
		next = reqArray[reqHead].next;
	}
	while (index != -1) {
		// checks the status of the send request with MPI
		err = MPI_Test(&reqArray[index].req, &flag, &status);
		if (!err) {
			// if the send succeeded
			if (flag) {
				// release the commQueue buffer for reuse
				err = queues[reqArray[index].node]-> ReturnBuffer(
						reqArray[index].buffer);
				// set return value to true indicating we did work
				retVal = true;

				if (err != CATASTROPHIC_FAILURE) {
					// release the request buffer for reuse
					PopReq(prev, index);
					index = prev;
				} else {
					// commQueue catastrophic failure
					DisplayCQError("ReturnBuffer failed");
					BroadcastAndEnd();
				}
			} else { // MPI_Test is false
				// see if this buffer currently being sent, if so, set the return flag
				if (queues[reqArray[index].node]->IsSendPending(
						reqArray[index].buffer)) {
					hasPendingSends = true;
				}
#ifdef ENABLE_FILE_LOGGING
				numBuffersUsed++;
#endif
			}
		} else {
			// there was a failure in checking the status through MPI
			DisplayMPIError("RecoverBuffers(), MPI_Test()", err);
			BroadcastAndEnd();
		}
		// set previous to current, and current to next
		prev = index;
		index = next;
		// if not at the end
		if (next != -1) {
			next = reqArray[next].next;
		}

#ifdef ENABLE_FILE_LOGGING
		if (LOG_LIMIT_AVAIL(COMM_QUEUE_PENDING_ID, 1))
		{
			LOG_VERBOSE(" (comm-queues) Recover buffer stats (%d of %d buffers used):\n", numBuffersUsed, NumBuffs*numProcs);
			for (int i = 0; i < numProcs; i++)
			{
				int numBuffsBeingSent = 0;
				int index = reqHead;
				int next;

				if (reqHead != -1)
				next = reqArray[reqHead].next;

				while (index != -1)
				{
					if (reqArray[index].node == i)
					numBuffsBeingSent++;

					index = next;

					if (next != -1)
					next = reqArray[next].next;
				}

				if (numBuffsBeingSent > 0)
				LOG_VERBOSE("   (comm-queues) Sending states still pending to node %d (%d buffers currently being sent).\n", i, numBuffsBeingSent);
			}
		}
#endif
	}
	return retVal;
}

//
// Receive the states reply message.  This increments the number of state reply messages
// sent from the node (used in busyness checking).
//
void commManager::ReceiveStatesReply() {
	MPI_Status stat;
	int err;
	int sendingRank;

	err = MPI_Recv(&sendingRank, MESSAGE_STATES_REPLY_INT_LENGTH, MPI_INT,
			MPI_ANY_SOURCE, MESSAGE_STATES_REPLY, MPI_COMM_WORLD, &stat);
	if (err) {
		DisplayMPIError("ReceiveStates(), MPI_Recv()", err);
		BroadcastAndEnd();
		return;
	}

	// sanity check
	assert(sendingRank == stat.MPI_SOURCE && sendingRank >= 0 && sendingRank
			< numProcs);

	// Increment the number of reply messages from this node
	m_stateReplyCount[sendingRank]++;

	LOG_VERBOSE(" (communicate) Node %d sent state message reply (reply count %d)\n", sendingRank, m_stateReplyCount[sendingRank]);
}

//
// It is called if there is some MPI message carrying states, and retrieves these states
// and enqueues them in the local consumption queue. If the worker is sleeping,
// wakes it up
//
void commManager::ReceiveStates() {
	LOG_VERBOSE(" (communicate) Entering ReceiveStates().\n");

	// initialize receive buffer to maximum size
	static char *buf = new char[BuffSize * StateLen];
	assert(buf);
	// stat includes the actual size received after MPI_Recv
	MPI_Status stat;
	int len = 0, err;

	err = MPI_Recv(buf, (BuffSize * StateLen), MPI_CHAR, MPI_ANY_SOURCE,
			MESSAGE_STATES, MPI_COMM_WORLD, &stat);
	if (err) {
		// MPI error in MPI_Receive()
		DisplayMPIError("ReceiveStates(), MPI_Receive()", err);
		BroadcastAndEnd();
		return;
	}
	// this will populate len with actual length of data
	err = MPI_Get_count(&stat, MPI_CHAR, &len);
	if (err) {
		// MPI error in MPI_Get_count()
		DisplayMPIError("ReceiveStates(), MPI_Get_count()", err);
		BroadcastAndEnd();
		return;
	}

	Received++;

	LOG_VERBOSE(" (communicate) Received states message from node %d (%d states), sending reply.\n", stat.MPI_SOURCE, len/sizeof(class state));

	// enqueue in local consumption queue (by calling addToLocalQueue)
	int newWork = (*queue)(buf, len);

	if (newWork != 0) { // should be always true
		// wake up the worker thread if in CheckStableCondition
		mutexes->LockMutex(MUTEX_WRKR_SLP);
		if (workerWaiting && workWaiting()) {
			workerWaiting = false;
			LOG_VERBOSE(" (threading) Worker waking up after receiving states.\n");
			mutexes->WakeUpMutex(SIGNAL_WRKR_SLP);
			// virtually returns only when the sleeping thread has unlocked the mutex
			// after having been waken up; then it immediately reacquires the lock
			mutexes->UnLockMutex(MUTEX_WRKR_SLP);
		} else
			mutexes->UnLockMutex(MUTEX_WRKR_SLP);
	}

	// States have been fully received, send the reply message
	MPI_Request req;
	err = MPI_Isend(&myRank, MESSAGE_STATES_REPLY_INT_LENGTH, MPI_INT,
			stat.MPI_SOURCE, MESSAGE_STATES_REPLY, MPI_COMM_WORLD, &req);
	MPI_Request_free(&req);

	if (err) {
		DisplayMPIError("ReceiveStates(), MPI_Isend()", err);
		BroadcastAndEnd();
		return;
	}

	nodeLoads[stat.MPI_SOURCE].reqFrom = false; //Patrick
	pendingPullRequest--;
}

//
// sets Terminate to true and wakes up worker thread if it is sleeping;
// the root gets the final number of states from the other nodes, while the
// other nodes sends their stats to the root.
// Finally, the communication thread is terminated
//
void commManager::End() {
	int err1;
	MPI_Request req;
	MPI_Status status;
	int numProcsStats = IsRoot() ? numProcs - 1 : 1;

	// lock mutex, set terminate and wake worker then release mutex
	mutexes->LockMutex(MUTEX_TERMINATE);
	Terminate = true;
	mutexes->UnLockMutex(MUTEX_TERMINATE);
	mutexes->LockMutex(MUTEX_WRKR_SLP);
	final_stats_buf1 = new struct final_stats1[numProcsStats];
	final_stats_buf1_d = new struct final_stats1_d[numProcsStats];
	final_stats_buf2 = new struct final_stats2[numProcsStats];
	final_stats_buf3 = new struct final_stats3[numProcsStats];
#ifdef HASHC
	if (args->print_trace.value) {
		final_hashmatrix_buf = new struct final_hashmatrix[numProcsStats];
		for (int i = 0; i < numProcsStats; i++)
		final_hashmatrix_buf[i].hashmatrix = new uint32_t[message_hashmatrix_ulong_uint_length];
	}
#endif
	if (Sent)
		Avg_states_in_msg = Avg_states_in_msg / Sent;
	else {
		unsigned char s[8];
		s[0] = s[1] = s[2] = s[3] = s[4] = s[5] = 0;
		s[6] = 0xf0;
		s[7] = 0x7f;
		/* this is infinite in IEEE 754 */
		Avg_states_in_msg = *((double *) s);
	}
	if (!IsRoot()) {
		// send local statistics to root
		// MPI_Barrier done after all this should allow to avoid MPI_Wait

		// unsigned long: number of states and of rules
		if (StateSet->IsNumEltsDouble()) {
			final_stats_buf1_d[0].num_elts = StateSet->NumElts_d();
			final_stats_buf1_d[0].rules_fired = Rules->NumRulesFired_d();
			err1 = MPI_Isend(&final_stats_buf1_d[0],
					MESSAGE_NUM_STATES_DOUBLE_LENGTH, MPI_DOUBLE, 0,
					MESSAGE_NUM_STATES_D, MPI_COMM_WORLD, &req);
		} else {
			final_stats_buf1[0].num_elts = StateSet->NumElts();
			final_stats_buf1[0].rules_fired = Rules->NumRulesFired();
			err1 = MPI_Isend(&final_stats_buf1[0],
					MESSAGE_NUM_STATES_ULONG_LENGTH, MPI_UNSIGNED_LONG, 0,
					MESSAGE_NUM_STATES, MPI_COMM_WORLD, &req);
		}
		if (err1) {
			DisplayMPIError("MPI_ISend() in End()", err1);
		}

		// unsigned int: number of messages sent, and max and min number of states in each msg
		final_stats_buf2[0].sent = Sent;
		final_stats_buf2[0].received = Received;
		final_stats_buf2[0].max_states_in_msg = Max_states_in_msg;
		final_stats_buf2[0].min_states_in_msg = Min_states_in_msg;
		err1 = MPI_Isend(&final_stats_buf2[0], MESSAGE_MESSAGES1_UINT_LENGTH,
				MPI_UNSIGNED, 0, MESSAGE_MESSAGES1, MPI_COMM_WORLD, &req);
		if (err1) {
			DisplayMPIError("MPI_ISend() in End()", err1);
		}

		// double: average number of states in each msg and local process time
		final_stats_buf3[0].avg_states_in_msg = Avg_states_in_msg;
		final_stats_buf3[0].proc_time = SecondsSinceStart();
		err1 = MPI_Isend(&final_stats_buf3[0], MESSAGE_MESSAGES2_DOUBLE_LENGTH,
				MPI_DOUBLE, 0, MESSAGE_MESSAGES2, MPI_COMM_WORLD, &req);
		if (err1) {
			DisplayMPIError("MPI_ISend() in End()", err1);
		}

#ifdef HASHC
		if (args->print_trace.value) {
			// unsigned long: number of states and of rules
			h3->gethashmatrix(final_hashmatrix_buf[0].hashmatrix);
			err1 = MPI_Isend(final_hashmatrix_buf[0].hashmatrix, message_hashmatrix_ulong_uint_length,
#if __WORDSIZE == 32
					MPI_UNSIGNED_LONG,
#else
					MPI_UNSIGNED,
#endif
					0, MESSAGE_HASHMATRIX, MPI_COMM_WORLD, &req);
			if(err1) {
				DisplayMPIError("MPI_ISend() in End()", err1);
			}
		}
#endif
	} else {
		// this is root, collect statistics from other nodes
		for (int rank = 1; rank < numProcs; rank++) {
			int read = 0, err, flag;
#ifdef HASHC
#define TO_BE_READ (args->print_trace.value? 4 : 3)
#else
#define TO_BE_READ 3
#endif
			while (read != TO_BE_READ) {
				err = MPI_Iprobe(rank, MESSAGE_NUM_STATES, MPI_COMM_WORLD,
						&flag, &status);
				if (err)
					DisplayMPIError("MPI_Iprobe() in End()", err);
				if (flag) {
					err1 = MPI_Recv(&final_stats_buf1[rank - 1],
							MESSAGE_NUM_STATES_ULONG_LENGTH, MPI_UNSIGNED_LONG,
							rank, MESSAGE_NUM_STATES, MPI_COMM_WORLD, &status);
					if (err1)
						DisplayMPIError("End(), MPI_Recv()", err1);
					StateSet->IncrNumEltsOthers(
							final_stats_buf1[rank - 1].num_elts);
					Rules->IncrNumRulesFiredOthers(
							final_stats_buf1[rank - 1].rules_fired);
					read++;
					is_final_stats_buf1_double = FALSE;
				}
				err = MPI_Iprobe(rank, MESSAGE_NUM_STATES_D, MPI_COMM_WORLD,
						&flag, &status);
				if (err)
					DisplayMPIError("MPI_Iprobe() in End()", err);
				if (flag) {
					err1 = MPI_Recv(&final_stats_buf1_d[rank - 1],
							MESSAGE_NUM_STATES_DOUBLE_LENGTH, MPI_DOUBLE, rank,
							MESSAGE_NUM_STATES_D, MPI_COMM_WORLD, &status);
					if (err1)
						DisplayMPIError("End(), MPI_Recv()", err1);
					StateSet->IncrNumEltsOthers(
							final_stats_buf1_d[rank - 1].num_elts);
					Rules->IncrNumRulesFiredOthers(
							final_stats_buf1_d[rank - 1].rules_fired);
					read++;
					is_final_stats_buf1_double = TRUE;
				}
				err = MPI_Iprobe(rank, MESSAGE_MESSAGES1, MPI_COMM_WORLD,
						&flag, &status);
				if (err)
					DisplayMPIError("MPI_Iprobe() in End()", err);
				if (flag) {
					err1 = MPI_Recv(&final_stats_buf2[rank - 1],
							MESSAGE_MESSAGES1_UINT_LENGTH, MPI_UNSIGNED, rank,
							MESSAGE_MESSAGES1, MPI_COMM_WORLD, &status);
					if (err1)
						DisplayMPIError("End(), MPI_Recv()", err1);
					read++;
				}
				err = MPI_Iprobe(rank, MESSAGE_MESSAGES2, MPI_COMM_WORLD,
						&flag, &status);
				if (err)
					DisplayMPIError("MPI_Iprobe() in End()", err);
				if (flag) {
					err1 = MPI_Recv(&final_stats_buf3[rank - 1],
							MESSAGE_MESSAGES2_DOUBLE_LENGTH, MPI_DOUBLE, rank,
							MESSAGE_MESSAGES2, MPI_COMM_WORLD, &status);
					if (err1)
						DisplayMPIError("End(), MPI_Recv()", err1);
					read++;
				}
#ifdef HASHC
				if (args->print_trace.value) {
					err = MPI_Iprobe(rank, MESSAGE_HASHMATRIX, MPI_COMM_WORLD, &flag, &status);
					if(err) DisplayMPIError("MPI_Iprobe() in End()", err);
					if(flag) {
						err1 = MPI_Recv(final_hashmatrix_buf[rank - 1].hashmatrix, message_hashmatrix_ulong_uint_length,
#if __WORDSIZE == 32
								MPI_UNSIGNED_LONG,
#else
								MPI_UNSIGNED,
#endif
								rank, MESSAGE_HASHMATRIX, MPI_COMM_WORLD, &status);
						if(err1) DisplayMPIError("End(), MPI_Recv()", err1);
						read++;
					}
				}
#endif
			}
		}
	}
	if (workerWaiting) {
		mutexes->WakeUpMutex(SIGNAL_WRKR_SLP);
	}
	mutexes->UnLockMutex(MUTEX_WRKR_SLP);

#if 0
	// synchronize MPI world and get final timestamp
	err1 = MPI_Barrier(MPI_COMM_WORLD);
	if(err1) {
		DisplayMPIError("MPI_Barrier()", err1);
	}
#endif
	fTime = MPI_Wtime();

	// again synch MPI world and finalize MPI; now moved and explicitly called by the worker thread (which is now alone)
	/*MPI_Barrier(MPI_COMM_WORLD);
	 MPI_Finalize();*/
	// end of the communcation thread
	pthread_exit(NULL);
}

//
// Putting this here allows to call SecondsSinceStart()
//
double commManager::GetProcTime(int rank) {
	if (rank)
		return final_stats_buf3[rank - 1].proc_time;
	else
		return SecondsSinceStart();
}

//
// Handles MPI tagged terminate messages by calling
// End() -- this is received when another node calls for
// group termination
//
void commManager::ReceiveTerminate() {
	int err;
	MPI_Status status;

	/* indeed, should be done only if HASHC and print_trace.value, otherwise less
	 info is needed */
	err = MPI_Recv(result_buf, MESSAGE_TERMINATE_ULONG_LENGTH,
			MPI_UNSIGNED_LONG, MPI_ANY_SOURCE, MESSAGE_TERMINATE,
			MPI_COMM_WORLD, &status);
	if (err) {
		DisplayMPIError("MPI_Recv in ReceiveTerminate()", err);
	}
	mutexes->LockMutex(MUTEX_RSLT);
	switch (result_buf[0]) {
	case 0:
		result = 'y';
		break;
	case 1:
		result = 'n';
		break;
	case 2:
		result = 'e';
		break;
	default:
		result = 'd';
		break;
	}
	mutexes->UnLockMutex(MUTEX_RSLT);
	if (IsRoot()) {
		mutexes->LockMutex(MUTEX_RNK);
		rank_error = result_buf[1];
		mutexes->UnLockMutex(MUTEX_RNK);
	}

	LOG_VERBOSE(" (communicate) Received terminate message.\n");

	End();
}

//
// Called in the comm thread main loop via StableCondTokenProc by a non-root node 
// whenever the token is valid and there is no more work to be done locally
// (neither by the worker nor by the communication thread).
// Updates the token and relays it to the next node in the MPI world (by this
// node opinion, the verification may terminate, since its worker is sleeping),
// with tag MESSAGE_TERMINATE_PROBE
//
void commManager::RelayToken() {
	int err;
	MPI_Request req;

	// If this node is black, the token must be sent black,
	//  if this node is white, the token color will be unchanged
	if (m_nodeColor == BLACK)
		scToken.color = BLACK;

	// The new node color becomes white
	m_nodeColor = WHITE;

	err = MPI_Isend(&scToken, MESSAGE_TERMINATE_PROBE_INT_LENGTH, MPI_INT,
			(myRank + 1) % numProcs, MESSAGE_TERMINATE_PROBE, MPI_COMM_WORLD,
			&req);

	LOG_VERBOSE(" (communicate-token) Currently %s, relaying %s token.\n", (m_nodeColor == BLACK ? "BLACK" : "WHITE"), (scToken.color == BLACK ? "BLACK" : "WHITE"));

	if (err) {
		DisplayMPIError("MPI_ISend() in RelayToken()", err);
		BroadcastAndEnd();
	}

	// token set to invalid since we no longer possess it
	scTokenValid = false;
}

//
// Called by root in the comm thread main loop via StableCondTokenProc if the token is 
// valid and no more work to be done locally (neither by the worker nor by the communication thread).
// The token is initialized to 0 sent and received (the root node counting on
// send and receive is added when the message comes back)
// Then, the token is sent to next rank in the MPI universe with tag MESSAGE_TERMINATE_PROBE
//
void commManager::InitSCTok() {
	int err;
	MPI_Request req;

	// Initializing a new probe, set the token's color to white
	//  The root node's color is also set white
	scToken.color = WHITE;
	m_nodeColor = WHITE;

	err = MPI_Isend(&scToken, MESSAGE_TERMINATE_PROBE_INT_LENGTH, MPI_INT,
			(myRank + 1) % numProcs, MESSAGE_TERMINATE_PROBE, MPI_COMM_WORLD,
			&req);

	LOG_VERBOSE(" (communicate-token) Root initializing token and relaying.\n");

	if (err) {
		DisplayMPIError("MPI_ISend() in InitSCTok()", err);
		BroadcastAndEnd();
	}
	// token set to invalid since we no longer possess it
	scTokenValid = false;
}

//
// See if there are any nodes that have been sent a group of states,
// but have not gotten around to receiving them.  In that case, for
// the purposes of the termination algorith, this node is still considered
// active.
//
bool commManager::isAwaitingStateReplies() {
	int nodeIndex;

	for (nodeIndex = 0; nodeIndex < numProcs; nodeIndex++) {
		// If a node has sent a reply for every state message that it has received,
		// its reply count will be 0.
		if (m_stateReplyCount[nodeIndex] != 0)
			return true; // There is some node who hasn't replied to all state messages sent
	}

	// All nodes have sent a reply for each state message sent
	return false;
}

//
// Returns true if some work may be performed locally, either by the worker
// (i.e., if the worker is not sleeping) or by the communication thread (at
// least one message can be sent or received
// Or if there are outstanding sent messages, the node is still
// considered active.
//
bool commManager::IsActive() {
	bool hasPendingSends = false;

	mutexes->LockMutex(MUTEX_WRKR_SLP);
	if (!workerWaiting) {
		mutexes->UnLockMutex(MUTEX_WRKR_SLP);
		return true;
	}
	mutexes->UnLockMutex(MUTEX_WRKR_SLP);

	if (DoSends() || ProcessMessages())
		return true;

	if (RecoverBuffers(hasPendingSends /*out*/)) {
		LOG_VERBOSE_LIMIT_FREQUENCY(ACTIVE_ID, 3, " (node-active) Has recovered some buffers.\n");
		return true;
	}

	// For the purposes of the termination algorithm, a node is considered active when it contains
	//  messages that have yet to be sent or has not received all of the send replies
	if (hasPendingSends) {
		LOG_VERBOSE_LIMIT_FREQUENCY(ACTIVE_ID, 3, " (node-active) Has pending sends.\n");
		return true;
	}

	if (isAwaitingStateReplies()) {
		LOG_VERBOSE_LIMIT_FREQUENCY(ACTIVE_ID, 3, " (node-active) Has outstanding state replies.\n");
		return true;
	}

	// No work to be done
	return false;
}

//
// Called in the comm thread main loop, calls either
// RelayToken for non-root node or InitSCTok for root node
// if there is no more work that can be done locally and the 
// token is here
//
void commManager::StableCondTokenProc() {
	if (!scTokenValid)
		return;
	if (IsActive())
		return;
	// No work can be done locally, so let's try to terminate the verification
	if (myRank != 0) { //non-root branch
		RelayToken();
	} else { //root branch
		InitSCTok();
	}
}

//
// Called if the received MPI tag is MESSAGE_TERMINATE_PROBE
// (so it is receiving something sent by RelayToken on InitSCTok of some other
// node). If there is no work that can be done locally, release the token to the
// next node if this is not the root; otherwise, retrieves the total number of
// messages sent and received (also by adding its own); if the counting mathes, the
// verification is terminated
//
void commManager::ReceiveTermProbe() {
	int err;
	MPI_Status status;

	// MPI receive token
	err = MPI_Recv(&scToken, MESSAGE_TERMINATE_PROBE_INT_LENGTH, MPI_INT,
			MPI_ANY_SOURCE, MESSAGE_TERMINATE_PROBE, MPI_COMM_WORLD, &status);
	if (err) {
		DisplayMPIError("MPI_Recv() in ReceiveTermProbe()", err);
		BroadcastAndEnd();
		return;
	}

	scTokenValid = true; // we possess the token

	LOG_VERBOSE(" (communicate-token) Currently %s, received %s token.\n", m_nodeColor == BLACK ? "BLACK" : "WHITE", scToken.color == BLACK ? "BLACK" : "WHITE");

	if (IsActive())
		return;
	// No work can be done locally, so let's try to terminate the verification
	if (!IsRoot())
		RelayToken();
	else {
		// we are the root node, check if the terminate conditions
		// are met (Total sent = Total received)

		// If the root's node color is white, and the token is white, computation has
		//  finished.
		if (m_nodeColor == WHITE && scToken.color == WHITE) {
			LOG_VERBOSE(" (communicate-token) Termination condition met.\n");
			BroadcastAndEnd();
		} // otherwise, the verification continues
	}
}

//
// It is called in the comm thread main loop, nad probes all the MPI channels for 
// any incoming message; if some incoming message is present, calls the appropriate 
// function handling it (on the basis of the message tag)
// Returns true if at least one message has been received, but could also not
// return at all (e.g., if ReceiveTerminate is called)
//
bool commManager::ProcessMessages() {
	int flag, err;
	bool retVal = false;
	MPI_Status status;

	// MESSAGE_STATES tag
	err = MPI_Iprobe(MPI_ANY_SOURCE, MESSAGE_STATES, MPI_COMM_WORLD, &flag,
			&status);
	if (err) {
		DisplayMPIError("MPI_Iprobe() in ProcessMessages()", err);
		BroadcastAndEnd();
	}
	if (flag) {
		ReceiveStates();
		retVal = true;
	}

	// MESSAGES_STATES_REPLY tag
	err = MPI_Iprobe(MPI_ANY_SOURCE, MESSAGE_STATES_REPLY, MPI_COMM_WORLD,
			&flag, &status);
	if (err) {
		DisplayMPIError("MPI_Iprobe() in ProcessMessages()", err);
		BroadcastAndEnd();
	}
	if (flag) {
		ReceiveStatesReply();
		retVal = true;
	}

	// Patrick
	// MESSAGE_REQ_STATES tag
	err = MPI_Iprobe(MPI_ANY_SOURCE, MESSAGE_REQ_STATES, MPI_COMM_WORLD, &flag,
			&status);
	if (err) {
		DisplayMPIError("MPI_Iprobe() in ProcessMessages()", err);
		BroadcastAndEnd();
	}
	if (flag) {
		handleStatePullRequest();
		retVal = true;
	}

	//Patrick
	err = MPI_Iprobe(MPI_ANY_SOURCE, MESSAGE_REQ_STATES_DENY_REPLY,
			MPI_COMM_WORLD, &flag, &status);
	if (err) {
		DisplayMPIError("MPI_Iprobe() in ProcessMessages()", err);
		BroadcastAndEnd();
	}
	if (flag) {
		ReceiveRequestStatesDenied();
		retVal = true;
	}

	// MESSAGE_TERMINATE tag
	err = MPI_Iprobe(MPI_ANY_SOURCE, MESSAGE_TERMINATE, MPI_COMM_WORLD, &flag,
			&status);
	if (err) {
		DisplayMPIError("MPI_Iprobe() in ProcessMessages()", err);
		BroadcastAndEnd();
	}
	if (flag) {
		ReceiveTerminate();
	}

	// MESSAGE_TERMINATE_PROBE tag
	err = MPI_Iprobe(MPI_ANY_SOURCE, MESSAGE_TERMINATE_PROBE, MPI_COMM_WORLD,
			&flag, &status);
	if (err) {
		DisplayMPIError("MPI_Iprobe() in ProcessMessages()", err);
		BroadcastAndEnd();
	}
	if (flag) {
		ReceiveTermProbe();
		retVal = true;
	}

	return retVal;
}

/**
 * Patrick
 * TODO
 */
/*void commManager::Send_Load_Idx() {
 int err;
 MPI_Request req;
 StateSet->QueueNumElts();

 err = MPI_Isend(result_buf, MESSAGE_LOAD_IDX_LENGTH, MPI_UNSIGNED_LONG,
 rank, MESSAGE_LOAD_IDX, MPI_COMM_WORLD, &req);
 if (err)
 DisplayMPIError("Send_Load_Idx(), MPI_Isend()", err);
 }*/

int* commManager::getMostLoadedNodes(int numNodes) {
	int *mostLoaded;
	if (numProcs != 2) {
		mostLoaded = new int[numNodes];

		int max;
		int maxIdx;

		for (int i = 0; i < numNodes; i++) {

			max = INT_MIN;
			maxIdx = -1;
			for (int j = 0; j < numProcs; j++) {
				if (j != myRank && nodeLoads[j].loadValue > max
						&& nodeLoads[j].reqFrom != true) {
					max = nodeLoads[j].loadValue;
					maxIdx = j;
				}
			}

			mostLoaded[i] = maxIdx;
			nodeLoads[maxIdx].reqFrom = true;
		}
	} else {
		mostLoaded = new int[1];
		mostLoaded[0] = !myRank; // with 2 procs, my rank is zero or one
		nodeLoads[!myRank].reqFrom = true;
	}

	return mostLoaded;
}

/**
 * Patrick
 * TODO
 */
void commManager::RequestStates(int numNodes) {
	//TODO lookup up load index and calculate host to pull from
	assert(numNodes < numProcs );
	MPI_Request req;
	int err = 0;
	int *requestFrom = getMostLoadedNodes(numNodes);
	for (int i = 0; i < numNodes; i++) {

		int sendToRank = requestFrom[i];
		LOG_VERBOSE(" (communicate) Sending pull request to Node %d.\n", sendToRank);
		err = MPI_Isend(&myRank, MESSAGE_REQ_STATES_LENGTH, MPI_UNSIGNED_LONG,
				sendToRank, MESSAGE_REQ_STATES, MPI_COMM_WORLD, &req);
		if (err)
			DisplayMPIError("RequestStates(), MPI_Isend()", err);

		nodeLoads[requestFrom[i]].reqFrom = true;
		pendingPullRequest++;
	}

	//TODO free requestFrom
}

/**
 * Patrick
 * TODO
 */
void commManager::ReceiveRequestStatesDenied() {
	int err;
	int replying_rank;
	MPI_Status stat;

	err = MPI_Recv(&replying_rank, MESSAGE_REQ_STATES_DENY_REPLY_LENGTH,
			MPI_UNSIGNED_LONG, MPI_ANY_SOURCE, MESSAGE_REQ_STATES_DENY_REPLY,
			MPI_COMM_WORLD, &stat);
	if (err) {
		// MPI error in MPI_Receive()
		DisplayMPIError("handleStatePullRequest(), MPI_Receive()", err);
		BroadcastAndEnd();
		return;
	}

	LOG_VERBOSE(" (communicate) Node %d denied pull request.\n", replying_rank);

	nodeLoads[replying_rank].reqFrom = false;
	pendingPullRequest--;
}

//
// This is the comm thread main loop, processing messages,
// recovering buffers, doing sends and doing stable condition 
// token processing loop
//
void commManager::Run_commMgr(void *dummy) {
	int yieldCount = 0;
	bool didWork = false;
	bool hasPendingSends = false; // ignored

	for (;;) {
		LOG_VERBOSE_LIMIT_FREQUENCY(COMM_LOOP_ID, 1, " (control-flow) Communication thread loop running.\n");

		// check for MPI messages to receive
		didWork = ProcessMessages();
		// check terminate flag, may be set by worker thread
		mutexes->LockMutex(MUTEX_TERMINATE);
		if (Terminate) {
			mutexes->UnLockMutex(MUTEX_TERMINATE);
			BroadcastAndEnd();
		}
		mutexes->UnLockMutex(MUTEX_TERMINATE);

		// Patrick request states if we are empty (and we only do it once)
		if (!workWaiting()) {
			if (pendingPullRequest == 0) {
				RequestStates(sqrtNumProcs);
			}
		}

		// checks for too many idle loops
		if (yieldCount < YIELD) {
			// uses MPI request stack to check all buffers in sending state
			didWork = RecoverBuffers(hasPendingSends /* cbj-ignored */);
			// send all commQueue buffers waiting to send
			didWork |= DoSends();
			// do any stable condition processing, if necessary
			StableCondTokenProc();
		} else { // too many idle loops
			pthread_yield();
			yieldCount = 0;
		}

		// increment check for idle loops if we didn't do any work
		if (!didWork)
			++yieldCount;
	}

}

void commManager::print_capacity() {
	unsigned long mem_alloc = memory_allocated();
	mutexes->LockMutex(MUTEX_PRINT); // Useless
	cout << "\nParallel Version:\n\tThe communication mechanism is storing "
			<< NumBuffs << " queue lines for each of the " << numProcs
			<< " nodes.\t\n\tEach queue line is able to store " << BuffSize
			<< " states.\n"
			<< "The total amount of memory used by the communication handling is "
			<< mem_alloc << " bytes, i.e. " << ((double) mem_alloc) / (1 << 20)
			<< "MB\n";
	mutexes->UnLockMutex(MUTEX_PRINT);
}

#ifdef HASHC_TRACE
//
// The following functions are to deal with the generation of the error trace
//

//
// Called by root when the trace has been completely printed, causes LoopForStates_nothreads to break the while
//
void commManager::ExitLoopForStates_nothreads()
{
	int err, dummy[numProcs - 1], sum_flags = 0, flags[numProcs - 1];
	MPI_Request req[numProcs - 1];
	MPI_Status status;

	for (int rank = 1; rank < numProcs; rank++) {
		/* don't mind what it is sent */
		err = MPI_Isend(&dummy[rank - 1], MESSAGE_TERMINATE_TRACE_INT_LENGTH, MPI_INT, rank, MESSAGE_TERMINATE_TRACE,
				MPI_COMM_WORLD, &req[rank - 1]);
		if (err)
		DisplayMPIError("ExitLoopForStates_nothreads(), MPI_Isend()", err);
		flags[rank - 1] = 0;
	}
	/* This while is to allow using local variables in sending */
	while (sum_flags < numProcs - 1) {
		for (int rank = 0; rank < numProcs - 1; rank++) {
			if (!flags[rank]) {
				err = MPI_Test(&req[rank], &flags[rank], &status);
				if (err)
				DisplayMPIError("MPI_Test() in ExitLoopForStates_nothreads()", err);
				if (flags[rank])
				sum_flags++;
			}
		}
	}
}

//
// Called by root to find a state in the trace file of some other node
// To fulfill the request, asks the node the relative info, waits for the answer and 
// then receives it when it is ready, then returns it
//
void commManager::QueryStateOnTrace_nothreads(unsigned long number, int rank, unsigned long *buf1, int *buf2)
{
	int err, flag[3] = {0, 0, 0}, flag_err;
	MPI_Request req;
	MPI_Status status;

	err = MPI_Isend(&number, MESSAGE_STATES_TRACE_QUERY_ULONG_LENGTH, MPI_UNSIGNED_LONG, rank, MESSAGE_STATES_TRACE_QUERY,
			MPI_COMM_WORLD, &req);
	if (err)
	DisplayMPIError("QueryStateOnTrace_nothreads(), MPI_Isend()", err);
	while (!flag[0] || !flag[1]) {
		if (!flag[0]) {
			err = MPI_Iprobe(rank, MESSAGE_STATES_TRACE_ANS1, MPI_COMM_WORLD, &flag[0], &status);
			if (err)
			DisplayMPIError("MPI_Iprobe() in QueryStateOnTrace_nothreads()", err);
			if (flag[0]) {
#if __WORDSIZE == 32
				err = MPI_Recv(buf1, MESSAGE_STATES_TRACE_ANS1_ULONG_LENGTH, MPI_UNSIGNED_LONG, rank, MESSAGE_STATES_TRACE_ANS1,
						MPI_COMM_WORLD, &status);
#else
				err = MPI_Recv(buf1, MESSAGE_STATES_TRACE_ANS1_ULONG_LENGTH, MPI_UNSIGNED_LONG_LONG, rank, MESSAGE_STATES_TRACE_ANS1,
						MPI_COMM_WORLD, &status);
#endif
			}
		}
		if (!flag[1]) {
			err = MPI_Iprobe(rank, MESSAGE_STATES_TRACE_ANS2, MPI_COMM_WORLD, &flag[1], &status);
			if (err)
			DisplayMPIError("MPI_Iprobe() in QueryStateOnTrace_nothreads()", err);
			if (flag[1]) {
				err = MPI_Recv(buf2, MESSAGE_STATES_TRACE_ANS2_INT_LENGTH, MPI_INT, rank, MESSAGE_STATES_TRACE_ANS2,
						MPI_COMM_WORLD, &status);
			}
		}
#if 0 
		/* problems when more than one node discovers an error */
		/* If something goes wrong with the generation of the trace */
		err = MPI_Iprobe(MPI_ANY_SOURCE, MESSAGE_TERMINATE, MPI_COMM_WORLD, &flag_err, &status);
		if (err)
		DisplayMPIError("MPI_Iprobe() in QueryStateOnTrace_nothreads()", err);
		if(flag_err)
		exit(2);
#endif
	}
}

//
// Called by non-root nodes: they keep waiting for states requests, which are served by looking on the local trace file
//
void commManager::LoopForStates_nothreads()
{
	int err, flag = 0, dummy;
	MPI_Status status;

	while (!flag) {
		err = MPI_Iprobe(0, MESSAGE_STATES_TRACE_QUERY, MPI_COMM_WORLD, &flag, &status);
		if (err)
		DisplayMPIError("MPI_Iprobe() in LoopForStates_nothreads()", err);
		if (flag)
		ReceiveQueryStatesOnTrace_nothreads();

		err = MPI_Iprobe(0, MESSAGE_TERMINATE_TRACE, MPI_COMM_WORLD, &flag, &status);
		if (err)
		DisplayMPIError("MPI_Iprobe() in LoopForStates_nothreads()", err);
		/* if received, flag is != 0, so the while is broken */
		/* this should be useless */
		if (flag) {
			err = MPI_Recv(&dummy, MESSAGE_TERMINATE_TRACE_INT_LENGTH, MPI_INT, 0, MESSAGE_TERMINATE_TRACE,
					MPI_COMM_WORLD, &status);
			if (err)
			DisplayMPIError("MPI_Iprobe() in LoopForStates_nothreads()", err);
		}
	}
}

//
// Called by non-root nodes inside LoopForStates_nothreads, to handle a state request
//
void commManager::ReceiveQueryStatesOnTrace_nothreads()
{
	int err, flag[3] = {0, 0, 0};
	unsigned long number;
	unsigned long buf1[3];
	int buf2;
	MPI_Request req[3];
	MPI_Status status;

	err = MPI_Recv(&number, MESSAGE_STATES_TRACE_QUERY_ULONG_LENGTH, MPI_UNSIGNED_LONG, 0, MESSAGE_STATES_TRACE_QUERY,
			MPI_COMM_WORLD, &status);
	if (err)
	DisplayMPIError("MPI_Recv() in ReceiveQueryStatesOnTrace_nothreads()", err);

	buf1[0] = TraceFile->read(number, GetRank())->previous;
	buf1[1] = TraceFile->read(number, GetRank())->c1;
	buf1[2] = TraceFile->read(number, GetRank())->c2;
#if __WORDSIZE == 32
	err = MPI_Isend(&buf1[0], MESSAGE_STATES_TRACE_ANS1_ULONG_LENGTH, MPI_UNSIGNED_LONG, 0, MESSAGE_STATES_TRACE_ANS1,
			MPI_COMM_WORLD, &req[0]);
#else
	err = MPI_Isend(&buf1[0], MESSAGE_STATES_TRACE_ANS1_ULONG_LENGTH, MPI_UNSIGNED_LONG_LONG, 0, MESSAGE_STATES_TRACE_ANS1,
			MPI_COMM_WORLD, &req[0]);
#endif
	if (err)
	DisplayMPIError("MPI_Isend() in ReceiveQueryStatesOnTrace_nothreads()", err);

	buf2 = TraceFile->read(number, GetRank())->rank;
	err = MPI_Isend(&buf2, MESSAGE_STATES_TRACE_ANS2_INT_LENGTH, MPI_INT, 0, MESSAGE_STATES_TRACE_ANS2,
			MPI_COMM_WORLD, &req[1]);
	if (err)
	DisplayMPIError("MPI_Isend() in ReceiveQueryStatesOnTrace_nothreads()", err);

	/* This while is to allow using local variables in asynchronous sending */
	while (!flag[0] || !flag[1]) {
		for (int i = 0; i < 2; i++) {
			if (!flag[i]) {
				err = MPI_Test(&req[i], &flag[i], &status);
				if (err)
				DisplayMPIError("MPI_Test() in ReceiveQueryStatesOnTrace_nothreads()", err);
			}
		}
	}
}
#endif
