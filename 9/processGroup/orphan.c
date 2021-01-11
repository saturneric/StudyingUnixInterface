#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/signal.h>

static void sig_hup(int singo) {
  printf("SIGHUP received, pid = %ld, signo = %d\n", (long) getpid(), singo);
}

static void pr_ids(char * name) {
  printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n", 
      name, (long)getpid(), (long)getppid(), (long)getpgrp(), (long)tcgetpgrp(STDIN_FILENO));

  fflush(stdout);
}

int main(void) {
  char c;
  pid_t pid;

  pr_ids("parent");

  if((pid = fork()) < 0) {
    printf("fork error\n");
    exit(-1);
  }
  else if (pid > 0) {
    printf("parent sleep...\n");
    sleep(3);
    printf("parent exit.\n");
  }
  else {
    pr_ids("child");
    signal(SIGHUP, sig_hup);
    kill(getpid(), SIGTSTP);
    pr_ids("child2");
    if(read(STDIN_FILENO, &c, 1) != 1){
      printf("read error %d on controlling TTY\n", errno);
      exit(-1);
    }
    exit(0);
  }

  return 0;
}
