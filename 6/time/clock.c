#include <sys/time.h>
#include <time.h>
#include <stdio.h>

int main(void) {
  struct timespec tsp;
  if(clock_gettime(CLOCK_REALTIME, &tsp) < 0) {
   printf("clock_gettime error\n");
   return -1;
  }

  printf("real time: %lu %lu\n", tsp.tv_sec, tsp.tv_nsec);;

  if(clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tsp) < 0) {
   printf("clock_gettime error\n");
   return -1;
  }
   
  printf("cpu time: %lu %lu\n", tsp.tv_sec, tsp.tv_nsec);;

  if(clock_gettime(CLOCK_THREAD_CPUTIME_ID, &tsp) < 0) {
   printf("clock_gettime error\n");
   return -1;
  }
   
  printf("thread time: %lu %lu\n", tsp.tv_sec, tsp.tv_nsec);;

  if(clock_getres(CLOCK_REALTIME, &tsp) < 0) {
    printf("clock_getres error\n");
    return -1;
  }

  printf("real time res: %lu %lu\n", tsp.tv_sec, tsp.tv_nsec);;

  return 0;
}
