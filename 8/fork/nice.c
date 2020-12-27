#include <unistd.h>
#include <sys/resource.h>
#include <stdio.h>

int main(void) {

  printf("NZERO: %d\n", sysconf(_SC_NZERO));

  if(nice(16) < 0) {
    printf("nice error\n");
    return -1;
  }

  int prior = getpriority(PRIO_PROCESS, 0);

  if(prior < 0) {
    printf("getpriority error\n");
    return -1;
  }

  printf("priority: %d\n", prior);
  

  return 0;
}
