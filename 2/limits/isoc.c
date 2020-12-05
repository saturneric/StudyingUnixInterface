#include <limits.h>
#include <stdio.h>

int main(void){
  // char
  printf("%d %d %d\n", CHAR_BIT, CHAR_MAX, CHAR_MIN);
  // signed char
  printf("%d %d\n", SCHAR_MAX, SCHAR_MIN);
  // unsigned char
  printf("%d\n", UCHAR_MAX);
  // int
  printf("%d %d\n", INT_MAX, INT_MIN);
  // short
  printf("%d %d\n", SHRT_MAX, SHRT_MIN);
  // long
  printf("%ld %ld\n", LONG_MAX, LONG_MIN);
  // long long
  printf("%lld %lld\n", LLONG_MAX, LLONG_MIN);
  // extra
  printf("%d %d %d\n", FOPEN_MAX, TMP_MAX, FILENAME_MAX);

  return 0;
}
