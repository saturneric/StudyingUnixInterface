#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int readFile(){
  
  int fd2 = open("./test/fileat", O_RDONLY);

  if(fd2 < 0){
    printf("Error in opening file fileat\n");
    return -1;
  }

  char buff2[1024];

  ssize_t rbit = read(fd2, buff2, 1024);

  if(rbit < 0){
    printf("Error in reading file fileat\n");
    return -1;
  }
  buff2[rbit] = 0;
  printf("rbit: %ld %s", rbit, buff2);

  close(fd2);
  return 0;

}

int main(void){
  int fd = open("./test/fileat", O_RDWR | O_APPEND);

  char buff[] = "Helloworld";

  ssize_t wbit = write(fd, buff, sizeof(buff));

  if(wbit != sizeof(buff)){
    printf("Error occur when wrote file fileat\n");
    return -1;
  }
  
  readFile();

  fsync(fd);

  readFile();
  
  close(fd);

  return 0;
}
