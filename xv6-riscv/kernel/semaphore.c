#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"
#include "semaphore.h"
#include "types.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"
#include "semaphore.h"

// initialize semaphore
void sem_init(struct semaphore *s, int value) {
  initlock(&s->lock, "semaphore");
  s->value = value;
}

// wait (P)
void sem_wait(struct semaphore *s) {
  acquire(&s->lock);

  while(s->value == 0) {
    sleep(s, &s->lock);  // block process
  }

  s->value--;

  release(&s->lock);
}

// signal (V)
void sem_signal(struct semaphore *s) {
  acquire(&s->lock);

  s->value++;
  wakeup(s);  // wake one waiting process

  release(&s->lock);
}
