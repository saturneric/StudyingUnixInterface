#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int makethread(void *(*fn)(void *), void *arg) {
  int err;
  pthread_t tid;
  pthread_attr_t attr;

  err = pthread_attr_init(&attr);
  if(err != 0)
    return err;
  err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  if(err == 0)
    err = pthread_create(&tid, &attr, fn, arg);
  pthread_attr_destroy(&attr);
  return err;
}

void *td_fn(void *arg) {
  printf("thread executing\n");
  pthread_exit(NULL);
}

int main(void) {
  int err = makethread(td_fn, NULL);
  sleep(3);
  return err;
}
