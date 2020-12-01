#include <limits.h>
#include <stdio.h>

int main(void){
  printf("%d %d %d\n", CHAR_BIT, CHAR_MAX, CHAR_MIN);
  printf("%d %d\n", INT_MAX, INT_MIN);
  printf("%d %d\n", SHRT_MAX, SHRT_MIN);
  printf("%ld %ld\n", LONG_MAX, LONG_MIN);
  printf("%lld %lld\n", LLONG_MAX, LLONG_MIN);

  printf("%d %d %d\n", FOPEN_MAX, TMP_MAX, FILENAME_MAX);
  return 0;
}
