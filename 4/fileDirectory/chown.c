#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int main(void){
  printf("%ld\n", pathconf("./chown.c",_POSIX_CHOWN_RESTRICTED));
  return 0;
}
