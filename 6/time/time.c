#include <time.h>
#include <stdio.h>

int main(void) {
  time_t t = time(NULL);
  printf("%lu\n", t);
  return 0;
}
