#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define RWRR S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

int main(void) {
  
  int fd = open("test/filefp", O_RDWR | O_CREAT | O_TRUNC, RWRR);
  
  if(fd == -1) {
    printf("open file error filefp\n");
    return -1;
  }

  FILE *fp = fdopen(fd, "w+");
  char buf[1024];
  
  if(setvbuf(fp, buf, _IOFBF, 1024)) {
    printf("setvbuf error\n");
    return -1;
  }

  if(ferror(fp)) {
    printf("io stream error\n");
    return -1;
  }

  if(feof(fp)) {
    printf("arrive the end of the file\n");
  }

  putc('H', fp);
  fputc('Y', fp);

  fputs(" Hello World!", fp);

  fflush(fp);

  fclose(fp);

  close(fd);

  return 0;
}
