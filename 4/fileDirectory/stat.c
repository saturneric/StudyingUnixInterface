#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int printStat(struct stat buf){

  printf("DEV: %ld UID: %d SIZE: %ld BLOCKS: %ld\n", buf.st_dev, buf.st_uid, buf.st_size, buf.st_blocks);
  printf("MODE: %d INO: %ld BLKSIZE: %ld GID: %d\n", buf.st_mode, buf.st_ino, buf.st_blksize, buf.st_gid);

  if(S_ISREG(buf.st_mode)){
    printf("a regular file\n");
  } 
  else if(S_ISDIR(buf.st_mode)) {
    printf("a directory\n");
  }
}

int main(void){
  struct stat buf;
  if(stat("./stat.c", &buf) == -1){
    printf("stat error\n");
    return -1;
  }
  
  printStat(buf);

  int fd = open(".", O_RDONLY);

  if(fd == -1){
    printf("open O_RDONLY failed\n");
    return -1;
  }

  if(fstat(fd, &buf) < 0){
    printf("fstat error\n");
    return -1;
  }

  printStat(buf);

  close(fd);

  return 0;
}
