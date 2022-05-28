#include "include.h"



int main() 
{
pid_t pid;

	if((pid = fork())<0) //创建进程b1
	{ printf("error");
}else if(pid == 0)     //进程B1空间
{  if((pid = fork())<0)  //创建B2进程
    printf("error");
  else if (pid>0)        //大于0 表示在B1空间
     exit(0);            //结束进程B1
                         
  sleep(2);              //进程B2，B1空间，因为B1进程结束，B2执行
 printf("second child,parent pid = %d\n",getppid());//输出父进程ID因为其父进程已经终止所以是1
 exit(0); //结束进程B2
}
if (waitpid(pid,NULL,0)!=pid)  //父进程空间
   printf("错误");
   


}




