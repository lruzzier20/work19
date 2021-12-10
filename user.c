#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#define READ 0
#define WRITE 1

int main(){
  char s[50];
  mkfifo("p1",0644);
  printf("%s\n",strerror(errno));
  mkfifo("p2",0644);
  while(1){
    printf("Enter a string:");
    fgets(s, 50, stdin);
    int input=open("p1", O_WRONLY | O_CREAT, 0644);
    write(input, s, sizeof(s));
    close(input);
    int output=open("p2", O_RDONLY | O_CREAT, 0644);
    read(output, s, sizeof(s));
    close(output);
    printf("Edited String: %s\n",s);
  }
  return 0;
}
