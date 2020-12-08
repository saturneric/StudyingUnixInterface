#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>

int main(void) {
  struct stat buf;

  if(stat("/dev/sda", &buf) < 0){
    printf("stat error for /dev/sda\n");
    return -1;
  }

  printf("dev = %ld\nrdev = %ld\n", buf.st_dev, buf.st_rdev);

  if(S_ISCHR(buf.st_mode)){
    printf("character device\n");
  }
  else if (S_ISBLK(buf.st_mode)){
    printf("block device\n");
  }
  else {
    printf("unkonwn device\n");
  }
  
  return 0;
}
