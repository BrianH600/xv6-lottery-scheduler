#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_

#include "spinlock.h"

struct semaphore {
  int value;              
  struct spinlock lock;   
};


void sem_init(struct semaphore *s, int value);
void sem_wait(struct semaphore *s);
void sem_signal(struct semaphore *s);

#endif
