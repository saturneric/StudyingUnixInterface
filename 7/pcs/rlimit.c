#include <sys/resource.h>
#include <stdio.h>

int printRLimit(int resource) {
  struct rlimit rlim;
  if (getrlimit(resource, &rlim) < 0) {
    printf("getrlimit error\n");
    return -1;
  }

  if(rlim.rlim_cur != RLIM_INFINITY)
    printf("CUR: %lu ", rlim.rlim_cur);
  else
    printf("CUR: (infinity) ");

  if(rlim.rlim_max != RLIM_INFINITY)
    printf("MAX: %lu ", rlim.rlim_max);
  else
    printf("MAX: (infinity) ");

  printf("\n");

  return 0;
}

int main(void) {

  printRLimit(RLIMIT_AS);
  printRLimit(RLIMIT_CPU);
  printRLimit(RLIMIT_DATA);
  printRLimit(RLIMIT_FSIZE);
  printRLimit(RLIMIT_STACK);
  printRLimit(RLIMIT_NPROC);
  printRLimit(RLIMIT_NICE);

  struct rlimit rlim;
  rlim.rlim_cur = 1024;
  rlim.rlim_max = 1024;

  if(setrlimit(RLIMIT_STACK, &rlim) < 0) {
    printf("setrlimit error\n");
  }

  printRLimit(RLIMIT_STACK);
  
  return 0;
}
