#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
  pid_t pid = fork();

  if (pid != 0) {
    pid_t pidp = getpid();
    pid_t ppidp = getpid();
    uid_t uidp = getuid(), euidp = geteuid();
    gid_t gidp = getgid(), egidp  = getegid();
    printf("Father Process PID %d PPID %d UID %d EUID %d GID %d EGID %d\n", pidp, ppidp, uidp, euidp, gidp, egidp);

    int status;
    pid_t pidc = wait(&status);
    printf("Child Process PID %d Exited, status %d.\n", pidc, status);
  }
  else {
    pid_t pidc = getpid();
    pid_t ppidc = getpid();
    uid_t uidc = getuid(), euidc = geteuid();
    gid_t gidc = getgid(), egidc  = getegid();
    printf("Child Process PID %d PPID %d UID %d EUID %d GID %d EGID %d\n", pidc, ppidc, uidc, euidc, gidc, egidc);
    exit(0);
  }
  return 0;
}
