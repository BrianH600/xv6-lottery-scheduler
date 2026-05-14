#include "kernel/types.h"
#include "user/user.h"

int main() {
  int i;

  for(i = 0; i < 3; i++){
    if(fork() == 0){
      printf("Process %d waiting\n", getpid());

      sem_wait();  // try to enter

      printf("Process %d IN critical section\n", getpid());
      sleep(10);

      printf("Process %d leaving\n", getpid());

      sem_signal(); // release

      exit(0);
    }
  }

  for(i = 0; i < 3; i++){
    wait(0);
  }

  exit(0);
}
