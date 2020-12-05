#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int readFile(int fd){

  char buff[1024];

  ssize_t rbit = pread(fd, buff, 1024, 0);
  
  if(rbit < 0){
    printf("Error in reading file\n");
    return -1;
  }
  
  buff[rbit] = '\0';

  printf("rbit: %ld %s\n", rbit, buff);

  return 0;

}

int main(void){
  int fd = open("./test/fileat", O_RDWR | O_SYNC);

  if(fd < 0){
    printf("Error in opening file fileat.\n");
    return -1;
  }
  
  readFile(fd);

  ssize_t wbit = pwrite(fd, "How", 3, 0);

  if(wbit < 0) {
    printf("Error in writing file.\n");
    return -1;
  }

  readFile(fd);

  close(fd);

  return 0;
}
