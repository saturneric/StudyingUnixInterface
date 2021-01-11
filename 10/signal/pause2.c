#include <signal.h>
#include <unistd.h>
#include <setjmp.h>
#include <stdio.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo) {
  longjmp(env_alrm, 1);
}

int main(void) {
  if(signal(SIGALRM, sig_alrm) == SIG_ERR) 
    return -1;
  if(setjmp(env_alrm) == 0) {
    alarm(3);
    pause();
  }
  return 0;
}
