#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
  int fd = open("./test/fileat", O_RDWR | O_SYNC);
  
  if(fd == -1){
    printf("Error in opening file fileat.\n");
  }

  char buff[1024];

  ssize_t rbit = read(fd, buff, 1024);

  if(rbit > 0)
    buff[rbit] = '\0';

  printf("%ld %s\n", rbit, buff);

  off_t off = lseek(fd, 0, SEEK_END);

  printf("offset: %ld\n", off);
  
  char buff2[32] = "Hello World!";

  ssize_t wbit = write(fd, buff2, 13);
  
  printf("wbit: %ld\n", wbit);
  

  return 0;
}
