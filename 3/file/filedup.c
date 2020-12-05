#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  int fd = open("./test/fileat", O_RDWR | O_SYNC);

  int fd2 = dup(fd);

  off_t off = lseek(fd, 3, SEEK_SET);

  if (off == -1) {
    printf("Fail to call lseek\n");
    return -1;
  }

  char buff[1024];

  int rbit = read(fd2, buff, 1024);

  if (rbit < 0) {
    printf("Error in reading file fileat");
    return -1;
  }

  buff[rbit] = 0;

  printf("rbit: %ld %s\n", rbit, buff);

  return 0;
}
