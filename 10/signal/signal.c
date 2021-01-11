#include <sys/signal.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void sig_usr(int);

int main(void) {
  if(signal(SIGUSR1, sig_usr) == SIG_ERR) {
    printf("can't catch SIGUSR1\n");
    exit(-1);
  }
  if(signal(SIGUSR2, sig_usr) == SIG_ERR) {
    printf("can't catch SIGUSR2\n");
    exit(-1);
  }

  for(;;)
    pause();

  return 0;
}

static void sig_usr(int signo) {
  if(signo == SIGUSR1) {
    printf("SIGUSR1 received\n");
  }
  else if(signo == SIGUSR2) {
    printf("SIGUSR2 recieved\n");
  }
  else
    printf("error %d received", signo);
}
