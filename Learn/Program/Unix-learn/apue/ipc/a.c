//ipc 管道 创建管道
#include "include.h"
#define MAXLINE   20

int main()
{
	int		 	n;
	int 		fd[2];
	pid_t   pid;
	char    line[MAXLINE];
OK
if(pipe(fd)<0)     //创建管道
	ERR
if((pid=fork())<0)   //pid=fork  要加括号;
  ERR
	else 
	OK
 if(pid>0)        //子进程空间
 {  S1
 		close(fd[0]);
    write(fd[1],"hello world\n",12);
 }
 else              //父进程空间
 {  sleep(2);
 		S2
     close(fd[1]);
    n=read(fd[0],line,MAXLINE);
		printf("%s\n",line);
	  write(STDOUT_FILENO,line,n);
 }
	exit(0);
} 