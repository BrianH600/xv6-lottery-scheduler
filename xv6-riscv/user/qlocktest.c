#include "kernel/types.h"
#include "user/user.h"

int main()
{
  int role = fork();
  int i;
  char *name;

  if(role == 0)
    name = "Child";
  else
    name = "Parent";

  for(i = 0; i < 5; i++){
    printf("%s entering section %d\n", name, i);
  }

  exit(0);
}
