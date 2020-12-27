#include <sys/times.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
  struct tms buf;

  for(int i = 0, x = 1; i < 1e8; i++) x*=2; 

  if(times(&buf) < 0) {
    printf("times error\n");
    return -1;
  }

  printf("utime: %ld stime: %ld cutime: %ld cstime: %ld\n", buf.tms_utime, buf.tms_cutime, buf.tms_cutime, buf.tms_cstime);

  printf("clk_tck: %d\n", sysconf(_SC_CLK_TCK));
  return 0;
}
