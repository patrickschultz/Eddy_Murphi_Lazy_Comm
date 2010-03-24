#ifndef __EDDY_COMMUNICATION_MANANGER_H__
#define __EDDY_COMMUNICATION_MANANGER_H__

/*#define DEBUG_ON*/

#ifdef DEBUG_ON
/*# define DBG(x)         x*/
# define DBG0(x)        { if(_global_debug_level >= 1){x;} }
# define DBG1(x)        { if(_global_debug_level >= 2){x;} }
# define DBG2(x)        { if(_global_debug_level >= 3){x;} }
# define PDEBUG(x)      { if(_global_pdbg) { x; } } 
# define QDEBUG(x)      { if(_global_qdebug) { x; } } 
#else
/*# define DBG(x)*/
# define DBG0(x)
# define DBG1(x)
# define DBG2(x)
# define PDEBUG(x)
# define QDEBUG(x)      
#endif

#ifdef SELF_CHECK_ON
# define CHECK(x)       x
# define CHECK1(x)      {if(_global_check_level >= 1){x;}}
# define CHECK2(x)      {if(_global_check_level >= 2){x;}}
#else
# define CHECK(x)
# define CHECK1(x)
# define CHECK2(x)
#endif

#include <mpi.h>
#include <pthread.h>
#include <string>
#include <iostream>
#include "mu_buffqueue.h"
#include "stdint.h"

using std::string;

/// MPI Message tags
#define MESSAGE_STATES			4
#define MESSAGE_TERMINATE		5
#define MESSAGE_TERMINATE_PROBE 	6
#define MESSAGE_NUM_STATES		7		// Term stats
#define MESSAGE_NUM_STATES_D		8	// Term stats
#define MESSAGE_MESSAGES1		9		// Term stats
#define MESSAGE_MESSAGES2		10		// Term stats
#define MESSAGE_HASHMATRIX		11
#define MESSAGE_STATES_TRACE_ANS1	12
#define MESSAGE_STATES_TRACE_ANS2	13
#define MESSAGE_STATES_TRACE_ANS3	14
#define MESSAGE_TERMINATE_TRACE		15
#define MESSAGE_STATES_TRACE_QUERY	16
#define MESSAGE_STATES_REPLY            17
#define MESSAGE_REQ_STATES			18

#define MESSAGE_REQ_STATES_DENY_REPLY	20

#define MESSAGE_STATES_REPLY_INT_LENGTH         1
#define MESSAGE_TERMINATE_ULONG_LENGTH 		3
#define MESSAGE_NUM_STATES_ULONG_LENGTH 	2
#define MESSAGE_NUM_STATES_DOUBLE_LENGTH 	2
#define MESSAGE_TERMINATE_PROBE_INT_LENGTH      1
#define MESSAGE_MESSAGES1_UINT_LENGTH		4
#define MESSAGE_MESSAGES2_DOUBLE_LENGTH		2
//#define MESSAGE_HASHMATRIX_ULONG_LENGTH		(BLOCKS_IN_WORLD*24)
#define MESSAGE_STATES_TRACE_ANS1_ULONG_LENGTH	3
#define MESSAGE_STATES_TRACE_ANS2_INT_LENGTH	1
#define MESSAGE_TERMINATE_TRACE_INT_LENGTH	1
#define MESSAGE_STATES_TRACE_QUERY_ULONG_LENGTH	1
#define MESSAGE_REQ_STATES_LENGTH	1
#define MESSAGE_REQ_STATES_DENY_REPLY_LENGTH	1

/* Allow to specify also at compilation time */
#ifndef YIELD 
#define YIELD 3 
#endif
#ifndef NO_AVAILABLE_BUFFERS_TRIALS
#define NO_AVAILABLE_BUFFERS_TRIALS		3
#endif

#define MINIMUM_QUEUE_FOR_PULL_REQUEST 400

class commQueue;

// function called upon comm thread creation
void* CommThreadEntry(void*);

static pthread_t commThread;

class commManager
{
public:
  commManager(void (*Hashstats)(int, unsigned long *, double *, bool *), int (*Queue)(char*, int), int (*workWaiting)(), 
		  unsigned long (*getQueueSize)(), void(*AcceptPullRequest)(int), int stateLen, int *argc, char*** argv);
  ~commManager();
  void InitializeCommQueues(int NumBuffs, int BuffSize);
  int Flush(int owner);
  int  PushState(char* data1, int owner);
  void handleStatePullRequest(); //Patrick
  void CheckStableCondition();
  void RequestStates(int); // Patrick
  void Run_commMgr(void *);

  void StartThread();
  inline bool IsRoot()       { return (myRank == 0); } 
  inline int Root()       { return 0; } 
  inline int GetNumProcs() {   return numProcs; }
  inline int GetRank()     { return myRank;     } 
  inline unsigned int GetSent()     { return Sent;     }
  inline unsigned int GetReceived() { return Received; } 
  void GetNumElts(int rank, unsigned long *res_ul, double *res_d, bool *res_b) { 
    if (rank) {
      if (!is_final_stats_buf1_double) {
	*res_b = false;
	*res_ul = final_stats_buf1[rank - 1].num_elts;
	*res_d = 0.0; /* useless */
      }
      else {
	*res_b = true;
	*res_d = final_stats_buf1_d[rank - 1].num_elts;
	*res_ul = 0; /* useless */
      }
    }
    else
      hashstats(0, res_ul, res_d, res_b); 
  }
  void GetNumRulesFired(int rank, unsigned long *res_ul, double *res_d, bool *res_b) { 
    if (rank) {
      if (!is_final_stats_buf1_double) {
	*res_b = false;
	*res_ul = final_stats_buf1[rank - 1].rules_fired;
	*res_d = 0.0; /* useless */
      }
      else {
	*res_b = true;
	*res_d = final_stats_buf1_d[rank - 1].rules_fired;
	*res_ul = 0; /* useless */
      }
    }
    else
      hashstats(1, res_ul, res_d, res_b); 
  }
  inline unsigned int GetSent(int rank) { if (rank) return final_stats_buf2[rank - 1].sent; else return Sent; }
  inline unsigned int GetReceived(int rank) { if (rank) return final_stats_buf2[rank - 1].received; else return Received; }
  inline unsigned int GetMaxMsgLength(int rank) { if (rank) return final_stats_buf2[rank - 1].max_states_in_msg; else return Max_states_in_msg; }
  inline unsigned int GetMinMsgLength(int rank) { if (rank) return final_stats_buf2[rank - 1].min_states_in_msg; else return Min_states_in_msg; }
  inline double GetAvgMsgLength(int rank) { if (rank) return final_stats_buf3[rank - 1].avg_states_in_msg; else return Avg_states_in_msg; }
#ifdef HASHC
  inline uint32_t *GetHashmatrix(int rank) { return final_hashmatrix_buf[rank - 1].hashmatrix; } /* always called with rank > 0 */
  inline void set_blocks_in_world (int length) { message_hashmatrix_ulong_uint_length = length*24; }
  inline unsigned long GetNumCurState () { return result_buf[2]; }
#endif
  inline double GetITime() { return iTime; } 
  inline double GetMPITime() { return fTime - iTime; }
  // returns thread of communication queue -- used for terminating
  // the worker thread (it 'joins' the comm thread)
  static inline  pthread_t *GetThread() { return &commThread; }
  double GetProcTime(int rank);
  void print_capacity();
  unsigned long memory_allocated();
  unsigned long memory_allocated(int BufSize, int BufCount);
  void DoBarrierAndFinalize();
#ifdef HASHC_TRACE
  void ExitLoopForStates_nothreads();
  void LoopForStates_nothreads();
  void QueryStateOnTrace_nothreads(unsigned long number, int rank, unsigned long *buf1, int *buf2);
#endif

private:
  void (*hashstats)(int, unsigned long *, double *, bool *);
  int (*queue)(char*, int);
  int (*workWaiting)();
  unsigned message_hashmatrix_ulong_uint_length;
  unsigned long (*queueSize)(); //Patrick
  void (*acceptPullRequest)(int); //Patrick

  int BuffSize, StateLen, AuxLen, NumBuffs; // communication queues tuning params
  commQueue **queues; // the communication queues
  unsigned int Received; // # of MPI_Recv performed by this node
  unsigned int Sent; // # of MPI_Isend performed by this node
  unsigned int Max_states_in_msg;
  unsigned int Min_states_in_msg;
  double Avg_states_in_msg;
  short *m_stateReplyCount;  // Reply count for state messages sent

  bool workerWaiting;
  int pendingPullRequest;  //Patrick


  int numProcs, myRank; // MPI info
  double iTime, fTime; // MPI time

  //Patrick
  struct nodeLoad{
	  int loadValue;
	  bool reqFrom;
  } *nodeLoads;

  int sqrtNumProcs;

  // request handling -- physical array for two logical linked lists
  struct reqStruct{
    MPI_Request req;
    int node;
    int buffer;
    int next;
  } *reqArray;
  int reqHead, idleHead; // heads of lists

  // buffers for final data exchange
  unsigned long result_buf[3];
  struct final_stats1 {
    unsigned long num_elts;
    unsigned long rules_fired;
  } *final_stats_buf1;
  struct final_stats1_d {
    double num_elts;
    double rules_fired;
  } *final_stats_buf1_d;
  bool is_final_stats_buf1_double;
  struct final_stats2 {
    unsigned int sent;
    unsigned int received;
    unsigned int max_states_in_msg;
    unsigned int min_states_in_msg;
  } *final_stats_buf2;
  struct final_stats3 {
    double avg_states_in_msg;
    double proc_time;
  } *final_stats_buf3;
#ifdef HASHC
  struct final_hashmatrix {
    //unsigned long hashmatrix[MESSAGE_HASHMATRIX_ULONG_LENGTH*sizeof(unsigned long)];
	  unsigned int *test;
	  uint32_t *hashmatrix;
  } *final_hashmatrix_buf;
#endif
  // token data
  enum TerminationColor { BLACK, WHITE };
  struct stable_cond_token{
    TerminationColor color;
  } scToken;
  bool scTokenValid; /* true if the current node holds the token */
  TerminationColor m_nodeColor;

  unsigned int no_available_buffers_stats[3];

  //helper functions
  bool PushReq(MPI_Request, int, int);
  void PopReq(int, int);
  bool ProcessMessages();
  void ReceiveStates();
  void ReceiveStatesReply();
  void ReceiveTerminate();
  void ReceiveTermProbe();
  int* getMostLoadedNodes(int); //Patrick
  void ReceiveRequestStatesDenied(); //Patrick
  void BroadcastTerminate();
  bool RecoverBuffers(bool &HasPendingSends);
  bool HasPendingSends();
  bool DoSends();
  void End();
  void StableCondTokenProc();
  void InitSCTok(); // send from root
  void RelayToken(); // send from non-root
  bool IsActive();
  void DisplayCQError(string); // comm queue errors
  void DisplayMPIError(string, int);
  void BroadcastAndEnd();
#ifdef HASHC_TRACE
  void ReceiveQueryStatesOnTrace_nothreads();
#endif
  bool isAwaitingStateReplies();
};

#endif
