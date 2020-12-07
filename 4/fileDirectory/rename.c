#include <fcntl.h>
#include <stdio.h>

int main(void) {
  if(renameat(AT_FDCWD, "test/test2", AT_FDCWD, "test/test3") < 0) {
    printf("rename error\n");
    return -1;
  }
  return 0;
}
