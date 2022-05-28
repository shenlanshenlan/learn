// 管道2

#include "include.h"
#define   MAX  1000
int mian(int argc,char *argv[])
{
   int 				 n;
	 int 				 fd[2];
	 pid_t 			 pid;
	 char 			*pager,*argv0;
   char        line[500];         
	 FILE 			*fp;            //文件流

   if(argc!=2)                        //如果参数不为2 出错
	  ERR;
		if((fp=fopen(argv[1],"r"))==NULL) //打开文件 注意返回的是指针
	 		ERR 
      if(pipe(fd)<0)  								//创建管道
			ERR
  			if((pid=fork())<0)						//创建进程
				ERR
				else if(pid>0)          //父进程空间
{    
				close(fd[0]);           //关闭管道读取缎
				
				while(fgets(line,MAX，fp)！=NULL）  //fgets一次读取一行
 		{
   		n=strlen(line);                     //获取读取的长度
			if(write(fd[1],line,n)!=n)
			ERR
		}
		if(ferror(fp))
		ERR
		close(fd[1]);
		if(waitpid(pid,NULL,0)<0)
		  ERR
			exit(0);
	}
	else                                      //子进程空间
	{
	 close(fd[1]);
	 if(fd[0]!=STDIN_FILENO)
	 {
	 if(dup2(fd[0],STDIN_FILENO)!=STDIN_FILENO)
	 ERR
	 close(fd[0]);
	}




}






