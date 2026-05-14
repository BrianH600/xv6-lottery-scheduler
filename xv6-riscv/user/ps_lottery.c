
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int main() {
  struct pstat st;
  if (getpinfo(&st) < 0) {
    printf("Error\n");
    exit(1);
  }
  printf("PID\tTICKETS\tTICKS\n");
  for (int i = 0; i < 64; i++) {
    if (st.inuse[i] && st.pid[i] > 2) { // Skip init/sh
      printf("%d\t%d\t%d\n", st.pid[i], st.tickets[i], st.ticks[i]);
    }
  }
  exit(0);
}
