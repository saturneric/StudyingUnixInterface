#include <signal.h>
#include <unistd.h>
#include <setjmp.h>
#include <stdio.h>

static void sig_alrm(int);
static jmp_buf env_alrm;

int main(void) {
  int n;
  char line[256];

  if(signal(SIGALRM, sig_alrm) == SIG_ERR) {
    printf("signal(SIGALRM) error\n");
    return -1;
  }
  
  if(setjmp(env_alrm) != 0) {
    printf("read timeout\n");
    return -1;
  }

  alarm(5);
  if((n = read(STDIN_FILENO, line, 256) < 0)) {
    printf("read error\n");
    return -1;
  }
  alarm(0);
  write(STDOUT_FILENO, line, n);
  return 0;
}

static void sig_alrm(int signo) {
  longjmp(env_alrm, 1);
}
