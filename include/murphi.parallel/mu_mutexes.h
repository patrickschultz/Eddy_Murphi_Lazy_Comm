#ifndef MU_MUTEXES_H
#define MU_MUTEXES_H
#include <pthread.h>

#define MUTEX_PRINT 0
#define MUTEX_Q 1
#define MUTEX_TERMINATE 2
#define MUTEX_WRKR_SLP 3
#define MUTEX_WTBA 4
#define MUTEX_WTBS 5
#define MUTEX_ACTV 6
#define MUTEX_RSLT 7
#define MUTEX_RNK 8

#define SIGNAL_PRINT 0
#define SIGNAL_Q 1
#define SIGNAL_TERMINATE 2
#define SIGNAL_WRKR_SLP 3
#define SIGNAL_WTBA 4
#define SIGNAL_WTBS 5
#define SIGNAL_ACTV 6
#define SIGNAL_RSLT 7
#define SIGNAL_RNK 8

#define NUM_MUTEXES 9

class Mutexes
{
private:
	int NumMutexes;
	pthread_mutex_t *mutexes;
	pthread_cond_t *signals;
public:
	Mutexes(int);
	~Mutexes();
	int LockMutex(int);
	//bool IsMutexLocked(int);
	int UnLockMutex(int);
	int WaitMutex(int);
	int WakeUpMutex(int);
};

#endif
