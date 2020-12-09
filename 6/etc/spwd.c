#include <shadow.h>
#include <stdio.h>

int main(void) {
  struct spwd *p_spwd = getspnam("eric");
  
  printf("%s %s %ld %lu\n", p_spwd->sp_namp, p_spwd->sp_pwdp, p_spwd->sp_flag, p_spwd->sp_max);

  printf("%ld %ld %ld\n", p_spwd->sp_min, p_spwd->sp_inact, p_spwd->sp_warn);

  endspent();

  return 0;
}
