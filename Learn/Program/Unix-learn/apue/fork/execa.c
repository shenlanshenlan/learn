#include "include.h"
#include <unistd.h>
pid_t pid;


int main() 
 {
char *argv[]={"xingke","yuxinji",NULL};
char *envp[]={NULL};



 pid=fork();
if(pid == 0){
  if(execl("/bin/sh","sh", "-c","date",(char *)0)<0)
      printf("error\n");
 else printf("ok\n");

 }
else 
printf("21\n");
return 0;
} 
