#include <unistd.h>
#include <errno.h>
#include <stdio.h>

extern int errno;

static long posix_version = 0;

static long xsi_version = 0;

int main(void) {

  // get interface version
  posix_version = sysconf(_SC_VERSION);
  xsi_version = sysconf(_SC_XOPEN_VERSION);

  printf("%ld %ld\n", posix_version, xsi_version);

  // sysconf
  printf("%ld\n", sysconf(_SC_ARG_MAX));
  printf("%ld %ld\n", sysconf(_SC_CHILD_MAX), sysconf(_SC_CLK_TCK));
  printf("%ld %ld\n", sysconf(_SC_LOGIN_NAME_MAX), sysconf(_SC_OPEN_MAX));
  printf("%ld\n", sysconf(_SC_SEM_NSEMS_MAX));

  if(!~sysconf(_SC_SEM_NSEMS_MAX) && errno == EINVAL){
    printf("Not a proper value.\n");
  } 

  printf("%ld %ld\n", sysconf(_SC_TIMER_MAX), sysconf(_SC_STREAM_MAX));

  // pathconf
  printf("%ld\n", pathconf("./conf.c", _PC_FILESIZEBITS));
  printf("%ld\n", pathconf("./conf.c", _PC_NAME_MAX));
  // printf("%ld\n", pathconf("./conf.c", _PC_TIMESTAMP_RESOLUTION));
  printf("%ld\n", pathconf("./conf.c", _PC_PATH_MAX));
  printf("%ld\n", pathconf("./conf.c", _PC_LINK_MAX));

  return 0;
}
