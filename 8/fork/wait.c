#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  pid_t pid = fork();

  if(pid != 0){
    
    pid = fork();

    if(pid != 0) {
      int status;
      pid_t pidr = waitpid(pid, &status, 0);

      printf("WPID %d %d RTN %d\n", pid, pidr, status);
      
      if(WIFEXITED(status)){
        printf("Child Process Exited Status %d.\n", WEXITSTATUS(status));
      }

      exit(0);

    }
    else {
      printf("CPID: %d\n", getpid());
      exit(2);
    }

  }
  else {
    printf("CPID: %d\n", getpid());
    exit(1);  
  }
  
}
