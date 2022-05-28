#include <unistd.h>
#include <stdio.h>
int a = 55;
int b = 66;
 
int glob = 6;

int
main(void)
{
 int os = 1;
 pid_t pid;

	printf(" 第一次输出a %d \n",a);

pid = fork();
if(pid==0)
{
a++;
	}


 printf("创建进程输出PID   %d\n",pid);
 printf("第二次输出A  %d\n",a);



  return 0;
}  
