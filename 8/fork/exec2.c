#include <unistd.h>
#include <stdio.h>

int main(void) {
  if(execl("./itptfile", "tools", "yeah", ".", NULL) < 0) {
    printf("exec error\n");
  }
  return 0;
}
