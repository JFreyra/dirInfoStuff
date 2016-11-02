#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <errno.h>
#include <sys/stat.h>

void main(){

  DIR *dir = opendir(".");
  struct dirent *dirent;

  if(dir == NULL){
    printf("Error : %d - %s\n",errno,strerror(errno));
    return;
  }

  while(dirent = readdir(dir))
    printf("%s\n",dirent->d_name);
  
}
