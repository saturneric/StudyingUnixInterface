#include <unistd.h>
#include <stdio.h>

int main(void) {
  if(chdir("/home/eric") < 0) {
    printf("chdir error\n");
    return -1;
  }

  char buf[1024];

  char *pbuf = getcwd(buf, 1024);
  printf("CWD: %s\n", pbuf);
  return 0;
}
