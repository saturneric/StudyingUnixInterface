#include <sys/utsname.h>
#include <stdio.h>

int main(void) {
  struct utsname utsn;

  if(uname(&utsn) < 0) {
    printf("uname error\n");
    return -1;
  }

  printf("%s %s %s %s\n", utsn.sysname, utsn.nodename, utsn.machine, utsn.release);
  printf("%s\n", utsn.version);
  return 0;
}
