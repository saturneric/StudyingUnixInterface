#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
  
  int fd = open("/home/eric", O_RDONLY);

  if(fd == -1) {
    printf("open error for directory .\n");
    return -1;
  }

  if(symlinkat("symlinks.c", fd, "test/symlinksl.c") < 0) {
    printf("symlink error\n");
    return -1;
  }

  close(fd);

  char buf[1024];
  ssize_t rbit = readlink("/home/eric/test/symlinksl.c", buf, 1024);

  if(rbit < 0) {
    printf("readlink error\n");
    return -1;
  }

  buf[rbit] = 0;

  printf("rbit: %d buf: %s\n", rbit, buf);

  return 0;
}
