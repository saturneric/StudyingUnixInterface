#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

#define OPEN_MAX_GUESS 256

int main(void){

  if(openmax == 0) { 
    errno = 0;
    if((openmax = sysconf(_SC_OPEN_MAX)) < 0){
       if(errno == 0)
        openmax = OPEN_MAX_GUESS;
       else
        printf("sysconf error for _SC_OPEN_MAX");
    }
  }

  printf("%ld\n", openmax);

}
