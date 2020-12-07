#include <unistd.h>
#include <stdio.h>

int main(void){
  if(access("./access.c", R_OK | W_OK) < 0){
    printf("access error for acccess.c\n");
  }
  else {
    printf("read and write access OK\n");
  }

  if(access("./access.c", R_OK | X_OK) < 0){
    printf("access error for acccess.c\n");
  }
  else {
    printf("exec access OK\n");
  }
  return 0;
}
