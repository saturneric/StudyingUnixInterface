#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define RWRWRW S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH

int main(void) {
  umask(0);
  if(creat("./test/test1", RWRWRW) < 0){
    printf("creat error for test1\n");
  }
  umask(S_IWGRP | S_IROTH  | S_IWOTH);

  if(creat("./test/test2", RWRWRW) < 0){
    printf("creat error for test1\n");
  }
}
