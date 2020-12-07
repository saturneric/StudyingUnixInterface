#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


int main(void) {
  int fd = open("./filetime.c", O_RDWR);
  
  if(fd == -1) {
    printf("open file eror filetime.c\n");
    return -1;
  }

  
  struct stat buf;

  if(fstat(fd, &buf) < 0){
    printf("stat error\n");
    return -1;
  }

  struct timespec atim = buf.st_atim,
                  ctim = buf.st_ctim, 
                  mtim = buf.st_mtim;

  printf("sec  time: %12ld %12ld %12ld\n", atim.tv_sec, ctim.tv_sec, mtim.tv_sec);
  printf("nsec time: %12ld %12ld %12ld\n", atim.tv_nsec, ctim.tv_nsec, mtim.tv_nsec);

  int fd1 = open("./test/test3", O_RDWR);

  if(fd1 == -1) {
    printf("open file error test3\n");
    return -1;
  }

  struct timespec times[2];

  times[0] = atim;
  times[1] = ctim;

  if(futimens(fd1, times) < 0) {
    printf("futimens error\n");
    return -1;
  }

  close(fd1);

  close(fd);

  return 0;
}
