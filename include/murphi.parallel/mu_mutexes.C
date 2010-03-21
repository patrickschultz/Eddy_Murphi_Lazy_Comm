#ifndef MU_MUTEXES_C
#define MU_MUTEXES_C
#include <pthread.h>
#include "mu_mutexes.h"

Mutexes::Mutexes(int num_mutexes) : NumMutexes(num_mutexes)
{
  mutexes = new pthread_mutex_t[NumMutexes];
  signals = new pthread_cond_t[NumMutexes];
  for (int i = 0; i < NumMutexes; i++) {
    pthread_mutex_init(&mutexes[i], NULL);
    pthread_cond_init(&signals[i], NULL);
  }
}

Mutexes::~Mutexes()
{
  for (int i = 0; i < NumMutexes; i++) {
    pthread_mutex_destroy(&mutexes[i]);
    pthread_cond_destroy(&signals[i]);
  }
  delete [] mutexes;
  delete [] signals;
}

int Mutexes::LockMutex(int mutex)
{
  if (mutex >= NumMutexes)
    return -1;
  pthread_mutex_lock(&mutexes[mutex]);
  return 0;
}

/*bool Mutexes::IsMutexLocked(int mutex)
{
  if (mutex >= NumMutexes)
    return false;
  if (pthread_mutex_trylock(&mutexes[mutex]) == EBUSY)
    return true;
  else {
    pthread_mutex_unlock(&mutexes[mutex]);
    return false;
  }
}*/

int Mutexes::UnLockMutex(int mutex)
{
  if (mutex >= NumMutexes)
    return -1;
  pthread_mutex_unlock(&mutexes[mutex]);
  return 0;
}

int Mutexes::WaitMutex(int mutex)
{
  if (mutex >= NumMutexes)
    return -1;
  pthread_cond_wait(&signals[mutex], &mutexes[mutex]);
  return 0;
}

int Mutexes::WakeUpMutex(int mutex)
{
  if (mutex >= NumMutexes)
    return -1;
  pthread_cond_signal(&signals[mutex]);
  return 0;
}

#endif
