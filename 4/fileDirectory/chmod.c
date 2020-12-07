#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define RWRWRW S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
#define RWRR S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

int main(void){
  int fd = open("./test/test2", O_RDWR);
  if(fd == -1){
    printf("open file test1 error\n");
  }
  
  fchmod(fd, RWRWRW);

  close(fd);

  chmod("./test/test1", RWRR);

  return 0;
}
