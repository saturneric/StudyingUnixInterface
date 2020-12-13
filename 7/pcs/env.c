#include <stdlib.h>
#include <stdio.h>

int main(void) {
  char *pbuf = getenv("HOME");
  printf("HOME: %s\n", pbuf);
  
  pbuf = getenv("LANG");
  printf("LANG: %s\n", pbuf);

  return 0;
}
