#include <stdio.h>

int main(void) {
  char buf[1024];

  FILE *fp = fmemopen(buf, sizeof(buf), "r+");

  fprintf(fp, "Hello World!");

  fseek(fp, 0, SEEK_SET);

  char buf2[1024];

  fscanf(fp, "%s", buf2);

  printf("buf2: %s\n", buf2);

  fclose(fp);

  char *pbuf = NULL;

  size_t buf_size = 1024u;

  FILE *fp2 = open_memstream(&pbuf, &buf_size);

  if(fp2 == NULL) {
   printf("open_memstream error\n");
   return -1;
  }

  for(int i = 0; i < 2048; i++){
    fprintf(fp2, "TTTest ");
  }
  
  printf("pbuf: %p\n", pbuf);

  fflush(fp2);

  printf("pbuf: %p\n", pbuf);

  for(int i = 0; i < 8192; i++){
    fprintf(fp2, "TTTest ERRRRR");
  }

  fflush(fp2);

  printf("pbuf: %p\n", pbuf);

  fclose(fp2);

  return 0;
}
