#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void sig_int(int);

int main(void) {
  sigset_t newmask, oldmask, waitmask;

  printf("program start\n");

  if(signal(SIGINT, sig_int) == SIG_ERR) {
    printf("signal(SIGINT) error\n");
    return -1;
  }
  sigemptyset(&waitmask);
  sigaddset(&waitmask, SIGUSR1);
  sigemptyset(&newmask);
  sigaddset(&newmask, SIGINT);

  if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
    printf("SIG_BLOCK error\n");
    return -1;
  }

  printf("in critical region\n");

  if(sigsuspend(&waitmask) != -1) {
    printf("sigsuspend error\n");
    return -1;
  }

  printf("after return from sigsuspend\n");

  if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
    printf("SIG_SETMASK error\n");
    return -1;
  }

  printf("program exit\n");

  return 0;
}

static void sig_int(int signo) {
  printf("caught sigint = %d\n", signo);
}
