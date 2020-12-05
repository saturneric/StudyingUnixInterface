#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define RWRR S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

int main(void) {
  int fd = open("./test/file", O_RDONLY | O_CREAT, RWRR);
  int fd2 = open("./test/", O_DIRECTORY | O_EXCL);

  printf("%d\n", fd);
  printf("%d\n", fd2);

  int fd3 = openat(fd2, "./fileat", O_TRUNC | O_RDWR | O_CREAT | O_SYNC, RWRR);
  
  int fd4 = creat("./test/filecreat", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

  off_t off = lseek(fd4, 8, SEEK_SET);
  
  off = lseek(fd4, -2, SEEK_CUR);

  off = lseek(fd4, 1024, SEEK_CUR);

  printf("%ld", off);

  close(fd4);

  close(fd3);

  close(fd2);

  close(fd);
  
  return 0;
}
