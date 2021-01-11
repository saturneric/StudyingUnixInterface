#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void prepare(void) {

  int err;
  
  printf("preparing locks...\n");
  if((err = pthread_mutex_lock(&lock1) != 0)) {
    printf("mutex lock error\n");
  }
  if((err = pthread_mutex_lock(&lock2)) != 0) {
    printf("mutex lock error\n");
  }
}

void parent(void) {

  int err;

  printf("parent unlocking locks...\n");
  if((err = pthread_mutex_unlock(&lock1)) != 0)
    printf("mutex unlock error\n");
  if((err = pthread_mutex_unlock(&lock2)) != 0)
    printf("mutex unlock error\n");
}

void child(void) {
  
  int err;

  printf("child unlocking locks...\n");
  if((err = pthread_mutex_unlock(&lock1)) != 0)
    printf("mutex unlock error\n");
  if((err = pthread_mutex_unlock(&lock2)) != 0)
    printf("mutex unlock error\n");
}

void * thr_fn(void *arg) {
  printf("thread started...\n");
  pause();
  return 0;
}

int main(void) {
  int err;
  pid_t pid;
  pthread_t tid;

  if((err = pthread_atfork(prepare, parent, child)) != 0) {
    printf("install fork handlers error\n");
    return -1;
  }
  if((err = pthread_create(&tid, NULL, thr_fn, 0)) != 0) {
    printf("create thread error\n");
    return -1;
  }

  sleep(2);
  printf("parent about to fork...\n");

  if((pid = fork()) < 0) {
    printf("fork failed\n");
    return -1;
  }
  else if (pid == 0) {
    printf("child return from fork\n");
    return 0;
  }
  else {
    printf("parent return from fork\n");
    return 0;
  }
  return 0;
}
