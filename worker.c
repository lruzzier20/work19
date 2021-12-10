#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#define READ 0
#define WRITE 1

char* cap(char* s, int size){
  int h;
  for(int i=0;i<size;i++){
    h=s[i];
    if(isalpha(s[i])){
      if(h>96){h=h-32;}else{h=h+32;}
    }
    s[i]=h;
  }
  return s;
}

int main(){
  char s[50];
  int fd=open("p1", O_RDONLY);
  int fd2=open("p2", O_WRONLY);
  while(1){
    read(fd, s, sizeof(s));
    write(fd2, cap(s, sizeof(s)), sizeof(s));
  }
  return 0;
}
