#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

#define RWXRR S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH

int main(void) {
  if(mkdir("/home/eric/test/testmkdir", RWXRR) < 0) {
    printf("mkdir error\n");
  }

  if(rmdir("/home/eric/test/testmkdir") < 0) {
    printf("rmdir error\n");
    return -1;
  }
  
  return 0;
}
