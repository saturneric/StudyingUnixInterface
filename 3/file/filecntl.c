#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int getFL(int fd) { return fcntl(fd, F_GETFL, 0); }

int main(void) {
  int fd = open("./test/fileat", O_RDWR);

  printf("FL: %d\n", getFL(fd));

  if (fcntl(fd, F_SETFL, getFL(fd) |  O_APPEND) < 0) {
    printf("fcntl F_SETFL error\n");
    return -1;
  }

  printf("FL: %d\n", getFL(fd));

  char buff[] = "Nope";
  int wbit = write(fd, buff, sizeof(buff));

  if (wbit < 0) {
    printf("write buff error\n");
    return -1;
  }

  close(fd);

  return 0;
}
