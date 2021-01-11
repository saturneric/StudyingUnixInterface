#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>

static void my_alarm(int signo) {
  struct passwd *rootptr;

  printf("in signal handler signo = %d\n", signo);
  if ((rootptr = getpwnam("root")) == NULL) {
    printf("getpwnam(root) error");
  }

  alarm(1);
}

int main(void) {
  struct passwd *ptr;

  signal(SIGALRM, my_alarm);
  alarm(1);

  for(;;) {
    if((ptr = getpwnam("eric")) == NULL)
        printf("getpwnam(eric) error");
    if(strcmp(ptr->pw_name, "eric") != 0) {
      printf("return value corrupted, pw_name = %s\n", ptr->pw_name);
    }
  }
}
