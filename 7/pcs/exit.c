#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

void func(void) {
  printf("calling func\n");
}

int main(void) {
  printf("ATEXIT_MAX: %ld\n", sysconf(_SC_ATEXIT_MAX));
  if(atexit(func)) {
    printf("atexit error\n");
    exit(-1);
  }
  exit(0);
}
