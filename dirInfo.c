#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <errno.h>
#include <sys/stat.h>

void dynamic_add(char **string, char *addition){
  *string = (char *)realloc(*string,strlen(*string)+strlen(addition)+4);
  strcat(*string,addition);
  strcat(*string,"\n   ");
}

void main(){

  DIR *dir = opendir(".");
  struct dirent *dirent;
  int size = 0;

  char *directories = (char *)malloc(sizeof(char));
  char *regfiles = (char *)malloc(sizeof(char));

  if(dir == NULL){
    printf("Error : %d - %s\n",errno,strerror(errno));
    return;
  }

  while(dirent = readdir(dir)){
    size += dirent->d_reclen;
    if(dirent->d_type == DT_DIR)
      dynamic_add(&directories,dirent->d_name);
    if(dirent->d_type == DT_REG)
      dynamic_add(&regfiles,dirent->d_name);
  }

  printf("\nDirectory Stats\n");
  printf("\n");
  printf("size: %d Bytes\n\n",size);
  printf("directories:\n   %s\n",directories);
  printf("regfiles:\n   %s\n",regfiles);
  
  free(directories);
  free(regfiles);

  return;
}
