#ifndef __EDDY_COMM_QUEUE_H__
#define __EDDY_COMM_QUEUE_H__

#include <pthread.h> 
#include <string>
#include <vector>

using std::vector;
using std::string;

//return codes
const int  SUCCESS  = 1;
const int  NO_AVAILABLE_BUFFERS = 2;
const int  CATASTROPHIC_FAILURE = 3;

//flags for the cQueue.state element

/** BS is the short for Buffer State */
enum CommQueueBufferState 
{
  BS_SEND = 0,    // sending  
  BS_ACT = 1,    // active
  BS_WSEND = 2,  // waiting to send
  BS_WACT = 3  // waiting to be active
};

//structure of data on 'qArray' [defined next]
struct cQueue
{  
public:
  cQueue();
  ~cQueue();
  cQueue(size_t st_len, size_t  buf_size, size_t  aux_len);

  bool is_full() { return numObjects == max_buf_size; } 
  inline int get_object_num() { return numObjects; }
  
  void append(char * state_info);
  unsigned long memory_allocated();
  static unsigned long memory_allocated(int BuffSize, int StateLen, int AuxLen);

public:  
  unsigned char *buf;
  int  numObjects;
  CommQueueBufferState buf_state;

  int  next;
  
  int  max_buf_size; 
  int  max_aux_len;
  int  state_len;
};

//
// NumProcs - 1 of this will be allocated 
// thus for all node there are M queues (or equivalently a queue with M lines), 
// each able to hold N states; here, M and N are given as command-line
// parameters (-bcv and -bsv respectively)
// Push are made only on the Active queue
// There is a WaitingToBeActive list (via array indexes)
// One of these become active because of a Push operation
// when a queue is full, one of the queues in WaitingToBeActive will become
// Active; the current Active becomes WaitingToBeSent...
//
class commQueue
{
public:
  commQueue(int bufSize = 1, int stLen = 1, int auxLen = 0, int numBufs = 1);
  ~commQueue(void);
  int Push(char*, int);
  int GetBufferToCopy(char**, int*, int*, bool);
  int ReturnBuffer(int);
  bool IsSendPending(int);
  unsigned long memory_allocated();
  static unsigned long memory_allocated(int BuffSize, int StateLen, int AuxLen, int NumBuffs);

private:
  const int MAX_BUFFER_SIZE;
  const int STATE_LENGTH;
  const int OBJ2_LEN;
  const int NUMBER_OF_QUEUE_BUFFERS;

  struct cQueue **qArray; //actual data struct

  int Active;     // index for the Active buffer
  int WaitingTBA; // index for the waiting to be active 'list'
  int WaitingTBS; // index for the waiting to be sent 'list'

  //these helper functions do the work of 'state changing' buffers
  void PutWTBAonA(void);
  void PutAonWTBS(void);
  void PutWTBSonS(void);
  void PutSonWTBA(int);
  void PutAonS(void);
};

#endif
