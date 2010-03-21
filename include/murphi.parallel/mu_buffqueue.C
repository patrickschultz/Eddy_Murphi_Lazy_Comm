#include <pthread.h>
#include <string>
#include "mu_buffqueue.h"
#include "mu_log.h"

/*****************************************************************************
 *
 *   The implementation of struct cQueue
 *
 *****************************************************************************/

cQueue::cQueue() 
  : buf(0), numObjects(0),  buf_state(BS_WACT), next(-1), 
    max_buf_size(0),   max_aux_len(0), state_len(0)
{} 

cQueue::cQueue(size_t st_len, size_t  buf_size, size_t aux_len) 
  : numObjects(0), 
    buf_state(BS_WACT), 
    next(-1), 
    max_buf_size(buf_size), 
    max_aux_len(aux_len),
    state_len(st_len)
{
  buf = new unsigned char[st_len * buf_size];
  memset(buf, 0, st_len * buf_size);
}


cQueue::~cQueue() 
{ 
  delete [] buf;
} 

void cQueue::append(char * state_info)
{
  memcpy(buf + numObjects * state_len, state_info, state_len);
  numObjects++;
}

//
// Total amount (in bytes) of memory allocated
//
unsigned long cQueue::memory_allocated()
{
  return (unsigned long)sizeof(cQueue) + 
	 (unsigned long)(sizeof(unsigned char)*state_len*max_buf_size);
}

//
// Total amount (in bytes) of memory allocated
//
unsigned long cQueue::memory_allocated(int BuffSize, int StateLen, int AuxLen)
{
  return (unsigned long)sizeof(cQueue) + 
	 (unsigned long)(sizeof(unsigned char)*BuffSize*StateLen);
}

/*****************************************************************************
 *
 *   The implementation of class commQueue
 *
 *****************************************************************************/

//
// the constructor creates and initializes mutexes, initializes and
// creates all buffers, and initializes indicies to logical
// 'stacks' on queue
//
commQueue::commQueue(int bufSize, int stLen, int auxLen, int  numBufs):
  MAX_BUFFER_SIZE(bufSize),STATE_LENGTH(stLen), OBJ2_LEN(auxLen), 
  NUMBER_OF_QUEUE_BUFFERS(numBufs)
{
  //loop through all buffers and initialize all
  qArray = new cQueue*[NUMBER_OF_QUEUE_BUFFERS];
  for(int tempIndx = 0; tempIndx < NUMBER_OF_QUEUE_BUFFERS; tempIndx++)
  {
    qArray[tempIndx] = new cQueue(STATE_LENGTH, MAX_BUFFER_SIZE, OBJ2_LEN);
    if(tempIndx < NUMBER_OF_QUEUE_BUFFERS - 1)
      qArray[tempIndx]->next = tempIndx + 1;
  }

  //initialize indicies
  WaitingTBA = 0;  //set to first element
  Active = -1; //set to inactive
  WaitingTBS = -1; //inactive
}

//
// the destructor deletes all allocated buffers, the qArray, destroys
// and deletes mutexes
//
commQueue::~commQueue(void)
{
  for(int x = 0; x < NUMBER_OF_QUEUE_BUFFERS; x++) delete qArray[x];
  delete []qArray;
}

/******************HELPERS************************/

//
// This requires ActiveMutex and WaitActMutex be locked
// pop from waiting to be active push to active
//
void commQueue::PutWTBAonA(void)
{
  Active = WaitingTBA;
  qArray[Active]->buf_state = BS_ACT;
  WaitingTBA = qArray[WaitingTBA]->next;
  qArray[Active]->next = -1;
}

//
// This call requires ActiveMutex and WaitSndMutex be locked
// pop from active push on waiting to be sent
//
void commQueue::PutAonWTBS(void)
{
  qArray[Active]->buf_state = BS_WSEND;
  qArray[Active]->next = WaitingTBS;
  WaitingTBS = Active;
  Active = -1;
}

//
// WaitSndMutex must be locked on this call
// pop waiting to be sent push to sending
//
void commQueue::PutWTBSonS(void)
{
  int tmpIndex = qArray[WaitingTBS]->next;
  qArray[WaitingTBS]->buf_state = BS_SEND;
  qArray[WaitingTBS]->next = -1;
  WaitingTBS = tmpIndex;
}

//
// WaitActMutex has to be locked to call this
// push a sending buffer onto waiting to be active
//
void commQueue::PutSonWTBA(int i)
{
  qArray[i]->numObjects = 0;
  qArray[i]->buf_state = BS_WACT;
  qArray[i]->next = WaitingTBA;
  WaitingTBA = i;
}

//
// ActiveMutex must be locked prior to this call
// put active on sending
//
void commQueue::PutAonS(void)
{
  qArray[Active]->buf_state = BS_SEND;
  Active = -1;
}

/****************************PUBLICS************************/

//
// public member pushes a state onto the queue
//
int commQueue::Push(char* data, int owner)
/* called by commManager::PushState su queue[owner] */
{
  int retVal = CATASTROPHIC_FAILURE; 
  // we did get a null pointer, no branches taken
  if (data == NULL){
    return retVal;
 }

  //if we haven't been passed a NULL pointer
  mutexes->LockMutex(MUTEX_ACTV); //acquire ActiveMutex
    
  if(Active == -1)
  { 
    mutexes->LockMutex(MUTEX_WTBA); //lock waiting to be active
    if(WaitingTBA != -1) //if there are waiting to be active
	PutWTBAonA();
    else
      {
#ifdef ENABLE_FILE_LOGGING
	// logging stats
	int logNumWTBS = 0, logNumSending = 0, logNumActive = 0, logNumWTBA = 0;
	for (int i = 0; i < NUMBER_OF_QUEUE_BUFFERS; i++)
	  {
	    if (qArray[i]->buf_state == BS_WSEND)
	      logNumWTBS++;
	    if (qArray[i]->buf_state == BS_ACT)
	      logNumActive++;
	    if (qArray[i]->buf_state == BS_SEND)
	      logNumSending++;
	    if (qArray[i]->buf_state == BS_WACT)
	      logNumWTBA++;
	  }

	LOG_VERBOSE_LIMIT_FREQUENCY(COMM_QUEUE_ID, 1, " (comm-queues) No available waiting-to-be-active buffers to push a new state to node %d (%d total, %d WTBS, %d sending, %d active, %d WTBA).\n",
				    owner, NUMBER_OF_QUEUE_BUFFERS, logNumWTBS, logNumSending, logNumActive, logNumWTBA);
#endif
      }
    mutexes->UnLockMutex(MUTEX_WTBA); 
    retVal = NO_AVAILABLE_BUFFERS;
    mutexes->UnLockMutex(MUTEX_ACTV);
    return retVal;
  }

  //if Active is' active
  if( ! qArray[Active]-> is_full() )
  { //if Active is not full
    qArray[Active]->append(data);
    retVal = SUCCESS;
  }
  else{ //if active is full
    mutexes->LockMutex(MUTEX_WTBS); //lock waiting to send
    PutAonWTBS();
    mutexes->UnLockMutex(MUTEX_WTBS); //release
    retVal = NO_AVAILABLE_BUFFERS;
  }

  mutexes->UnLockMutex(MUTEX_ACTV); //release ActiveMutex  
  return retVal;
}

//
// gets a pointer to a buffer to copy -- will be safe to use until
// return buffer is called on its index
//
int commQueue::GetBufferToCopy(char** data, int* len, int* index, bool force)
{
  int retVal = CATASTROPHIC_FAILURE;
  if((data) && (len) && (index)){ //if our parameter pointers are not null
    mutexes->LockMutex(MUTEX_WTBS); //lock waiting to send
    if(WaitingTBS != -1){
      *data = (char*)( qArray[WaitingTBS]->buf );
      *len = qArray[WaitingTBS]->numObjects * STATE_LENGTH;
      *index = WaitingTBS;
      PutWTBSonS();
      retVal = SUCCESS;
      mutexes->UnLockMutex(MUTEX_WTBS); //release waiting to send
    }
    else{ //WaitingTBS is empty
      mutexes->UnLockMutex(MUTEX_WTBS); //release WTS
      if ( !force ) { //if the force flag is not set
	*len = 0;
	*data = NULL;
	*index = -1;
	retVal = NO_AVAILABLE_BUFFERS;
      }
      else{   //force is true
	mutexes->LockMutex(MUTEX_ACTV); //lock Active
	//if there is an Active buf with data in it
	if ( (Active != -1) && (qArray[Active]->numObjects) ) {
	  *data = (char*) ( qArray[Active]->buf );
	  *len = qArray[Active]->numObjects * STATE_LENGTH;
	  *index = Active;
	  PutAonS();
	  mutexes->UnLockMutex(MUTEX_ACTV); //unlock Active
	  retVal = SUCCESS;
	}
	else{ // there are no active to force
	  mutexes->UnLockMutex(MUTEX_ACTV); //unlock Active
	  *len = 0;
	  *data = NULL;
	  *index = -1;
	  retVal = NO_AVAILABLE_BUFFERS;
	}
      }
    }
  }// no branches taken if passed any NULL pointers
  return retVal;
}

//
// returns a buffer that was issued by pointer in 'GetBufferToCopy'
//
int commQueue::ReturnBuffer(int i)
{
  int retVal = CATASTROPHIC_FAILURE;

  // return if i is out of range
  if ( i < 0 || i > NUMBER_OF_QUEUE_BUFFERS ) return retVal;
  
  //if buffer i points to is in send mode
  if ( qArray[i]->buf_state == BS_SEND )
  { 
    mutexes->LockMutex(MUTEX_WTBA); //lock waiting to be active
    PutSonWTBA(i);
    mutexes->UnLockMutex(MUTEX_WTBA); //unlock waiting to be active
    retVal = SUCCESS;
  }
  return retVal;
}

//
// returns whether the buffer is currently being sent
//
bool commQueue::IsSendPending(int i)
{
  return qArray[i]->buf_state == BS_SEND;
}

//
// Total amount (in bytes) of memory allocated
//
unsigned long commQueue::memory_allocated()
{
  return (unsigned long)sizeof(commQueue) + 
	 (unsigned long)(sizeof(cQueue *)*NUMBER_OF_QUEUE_BUFFERS) +
	 (unsigned long)(qArray[0]->memory_allocated()*NUMBER_OF_QUEUE_BUFFERS);
}

//
// Total amount (in bytes) of memory allocated
//
unsigned long commQueue::memory_allocated(int BuffSize, int StateLen, int AuxLen, int NumBuffs)
{
  return (unsigned long)sizeof(commQueue) + 
	 (unsigned long)(sizeof(cQueue *)*NumBuffs) +
	 (unsigned long)(cQueue::memory_allocated(BuffSize, StateLen, AuxLen)*NumBuffs);
}

