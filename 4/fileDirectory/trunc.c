#include <unistd.h>
#include <stdio.h>

int main(void){
  if(truncate("./test/test1", 256) < 0) {
    printf("truncate error for file test1\n");
  }
  return 0;
}
