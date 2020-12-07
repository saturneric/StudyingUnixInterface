#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

extern int errno;

int main(void) {
  int fd = open("./links.c", O_RDWR);

  if(fd == -1) {
    printf("oprn error test1\n");
    return -1;
  }
  
  struct stat buf;

  if(fstat(fd, &buf) < 0) {
    printf("fstat error\n");
    return -1;
  }

  printf("%lu\n", buf.st_nlink);

  close(fd);

  fd = open(".", O_RDONLY);

  if(fd == -1){
    printf("open error .\n");
    return -1;
  }

  int fd2 = open("/home/eric", O_RDONLY);

  if(fd2 == -1){
    printf("open error ~\n");
    return -1;
  }
  
  if(linkat(fd, "links.c", fd2, "test/linksl.c", 0) < 0) {
    printf("linkat error\n");
    if(errno != 0) {
      printf("strerr: %s\n", strerror(errno)); 
    }
  }

  if(unlinkat(fd2, "test/linksl.c", 0) < 0) {
    printf("unlinkat error\n");
    return -1;
  }

  close(fd);
  close(fd2);


  return 0;
}
