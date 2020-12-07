#include <dirent.h>
#include <stdio.h>

int main(void) {
  DIR *pdir = opendir(".");

  if(pdir == NULL) {
    printf("opendir error\n");
    return -1;
  }

 struct dirent *pdirent = NULL;
  
 while((pdirent = readdir(pdir)) != NULL){
   long index = telldir(pdir);
   printf("%15s %18ld %lu\n", pdirent->d_name, index, pdirent->d_ino);

 }

 closedir(pdir);

  return 0;
}
