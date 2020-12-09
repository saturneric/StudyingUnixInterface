#include <pwd.h>
#include <stdio.h>


int main(void) {
  
  struct passwd *p_pwd = getpwnam("eric");

  printf("%d %d %s %s %s\n", p_pwd->pw_uid, p_pwd->pw_gid, p_pwd->pw_name, p_pwd->pw_shell, p_pwd->pw_passwd);


  while((p_pwd = getpwent()) != NULL) {
    printf("%d %d %s %s\n", p_pwd->pw_uid, p_pwd->pw_gid, p_pwd->pw_name, p_pwd->pw_shell);
  }

  endpwent();
  
  return 0;
}
