#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>


int main(void) {
  FILE *fp = fopen("./test/filefp", "r+");

  char buf[1024];

  char *pbuf = fgets(buf, 1024, fp);
  
  printf("buf: %s\n", buf);

  fseek(fp, 0, SEEK_END);

  fprintf(fp, "num: %d", 123456);
  
  fpos_t off;

  fgetpos(fp, &off);

  printf("off: %lu\n", off);

  int fd = fileno(fp);
  
  struct stat st;

  if(fstat(fd, &st) < 0) {
    printf("stat error fd\n");
    return -1;
  }
  
  printf("dev: %ld\n", st.st_dev);

  fclose(fp);
  close(fd);

  return 0;
}
