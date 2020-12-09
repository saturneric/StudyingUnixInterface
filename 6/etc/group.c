#include <grp.h>
#include <stdio.h>

int main(void){
  
  struct group *p_gp = getgrnam("sudo");
  
  if(p_gp == NULL) {
    printf("getgrgid error\n");
    return -1;
  }

  printf("%d %s", p_gp->gr_gid, p_gp->gr_name);

  char **p_men = p_gp->gr_mem;

  while(*p_men != NULL){
    printf(" %s", *p_men);
    p_men++;
  }

  printf("\n");

  return 0;
}
