#include <errno.h>
#include <unistd.h>
#include <stdio.h>


int main(void){

  printf("%ld %d %d\n", _POSIX_ASYNCHRONOUS_IO, _POSIX_JOB_CONTROL, _POSIX_SHELL);
  printf("%ld %ld %ld\n", _POSIX_SPIN_LOCKS, _POSIX_THREADS, _POSIX_TIMERS);
  printf("%d %ld %d\n", _XOPEN_REALTIME, sysconf(_SC_XOPEN_CRYPT), _XOPEN_SHM);

  if(errno != 0){
    printf("sysconf error for _SC_XOPEN_CRYPT\n");
  }

  printf("%ld\n", pathconf("./openmax.c", _PC_ASYNC_IO));
  if(errno != 0){
    printf("sysconf error for _PC_ASYNC_IO\n");
  }

  printf("%ld\n", pathconf("./openmax.c", _PC_CHOWN_RESTRICTED));

  return 0;
}
