#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void sig_alarm(int signo) {

}

int main(void) {
  if(signal(SIGALRM,  sig_alarm) == SIG_ERR)
    return -1;

  alarm(3);
  pause();
  return alarm(0);
}
