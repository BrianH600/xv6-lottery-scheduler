#include "kernel/types.h"
#include "user/user.h"

int main(void)
 {
  printf("Processes running: %d\n", getprocs());
  exit(0);
}
