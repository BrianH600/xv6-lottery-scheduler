#include "kernel/types.h"
#include "user/user.h"

int main() {
  int counts[] = {30, 20, 10};
  
  for (int i = 0; i < 3; i++) {
    int pid = fork();
    if (pid == 0) { // Child process
      settickets(counts[i]);
      for (;;) {} // Work loop
    }
  }
  exit(0);
}
