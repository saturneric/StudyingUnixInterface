#include <unistd.h>
#include <stdio.h>

int main(void) {
  char *name = getlogin();

  printf("%s\n", name);

  return 0;
}
