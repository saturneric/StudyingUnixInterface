#include <limits.h>
#include <stdio.h>

int main(void){
  
  // the length of the args of exec()
  printf("%d\n", _POSIX_ARG_MAX);
  // the num of child process under a real user id
  printf("%d\n", _POSIX_CHILD_MAX);
  // some var about file and path
  printf("%d %d %d\n", _POSIX_OPEN_MAX, _POSIX_NAME_MAX, _POSIX_PATH_MAX);
  // something further
  printf("%d %d %d\n", _POSIX_LOGIN_NAME_MAX, _POSIX_MAX_CANON, _POSIX_MAX_INPUT);
  // more
  printf("%d %d %d\n", _POSIX_SSIZE_MAX, _POSIX_SEM_NSEMS_MAX, _POSIX_TIMER_MAX);
 
  // different between the real value and define value
  printf("%d %d\n", _POSIX_TTY_NAME_MAX, TTY_NAME_MAX);

  return 0;
}

