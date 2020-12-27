#include <unistd.h>
#include <stdio.h>

int main(void) {
  printf("exec fork.c -> b.out\n");
  if(execl("./b.out", NULL) < 0) {
      printf("execl error\n");
  }
  return 0;
}
