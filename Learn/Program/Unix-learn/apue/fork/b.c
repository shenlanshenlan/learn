#include <sys/wait.h>
#include <stdio.h>
#include "pr_exit.h"
#include <stdlib.h>
int main() 
{
pid_t id;
int status;
int no;
if((id = fork())<0)	
  	printf("creat fork error");
else
		if( id == 0)
		exit(7);        //子进程结束

no = wait(&status);  //父进程执行空间
printf("%d\n",no);
 	if(wait(&status) !=id);
  pr_exit(status);
  printf("///////11111////////////////");
/////////////////////////////发送信号
if((id = fork())<0)	
  	printf("creat fork error");
else
		if( id == 0)
		abort();        //子进程结束

 	if(wait(&status) !=id);
 printf("wait error:");
  pr_exit(status);
  printf("///////22222////////////////////");
//////////////////////////除零错误

if((id = fork())<0)	
  	printf("creat fork error");
else
		if( id == 0)
		 status/=0;     //子进程结束

 	if(wait(&status) !=id);
printf("wait error");
  pr_exit(status);


printf("////////////////3333////////////////");

return 0;
}
