#include <stdio.h>
#include <time.h>


void printTm(struct tm *ptm) {
  printf("%d-%d-%d\n", 1900 + ptm->tm_year, 1 + ptm->tm_mon, ptm->tm_mday);
  printf("%d:%d:%d\n", ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
  printf("\n");
}

int main(void) {
  time_t t = time(NULL);
  struct tm * ptm = gmtime(&t);

  printTm(ptm);

  ptm = localtime(&t);

  printTm(ptm);

  t = mktime(ptm);

  printf("time: %lu\n", t);

  char buf[1024];

  size_t wbit = strftime(buf , sizeof(buf), "%D %T  %r %Z", ptm);

  if(wbit == 0) {
    printf("strftime error\n");
    return -1;
  }

  printf("format: %s\n", buf);

  sprintf(buf, "09/04/00 1:00:00");

  strptime((const char *)buf, "%x %X", ptm);

  wbit = strftime(buf , sizeof(buf), "%D %T  %r %Z", ptm);

  if(wbit == 0) {
    printf("strftime error\n");
    return -1;
  }

  printf("check format: %s\n", buf);
  
  return 0;
}
