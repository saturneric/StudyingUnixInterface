#include <stdio.h>

int main(void) {
  char buf[L_tmpnam];
 
  char *pbuf = tmpnam(buf);

  printf("tmpnam: %s\n", pbuf);

  FILE *fp = tmpfile();
  
  if(fp == NULL) {
    printf("create tmp file error\n");
    return -1;
  }

  fputs("Hellow World!", fp);
  rewind(fp);
  
  char buf2[1024];

  if(fgets(buf2, sizeof(buf2), fp) == NULL){
    printf("fgets error\n");
    return -1;
  }

  fputs(buf2, stdout);

  fclose(fp);



  return 0;
}
