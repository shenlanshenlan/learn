//服务器测试

#include "k.h"
void  str_echo(int sockfd); 

void  sig_chld()
{
pid_t  pid;
int  	 stat;
  while((pid = waitpid(-1,&stat,WNOHANG))>0)
			printf("child %d terminatd\n",pid);
			return;
}
 
int
main(int argc,char **argv)
{   

 	int				 listenfd,connfd;
	pid_t			 childpid;
	socklen_t  clilen;
	struct sockaddr_in cliaddr,servaddr;
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(9810);
	
	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	listen(listenfd,20);
	
	 
for( ;  ; )
{    clilen = sizeof(cliaddr);
	   connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&clilen);
		/*if((childpid = fork()) == 0) //创建进程=0子进程空间
	 	{  OK
		close(listenfd);						 //关闭监听socket
		 str_echo(connfd);					 //处理函数
		 exit(0);
		}*/
	close(connfd);    
								 //父进程关闭套接字
								 
	}
	 
	 
}



void str_echo(int sockfd)
{
	ssize_t n;
	char		buf[MAX];
	again:
	 while((n = read(sockfd,buf,MAX))>0)
	 write(sockfd,buf,n);
	 if(n<0)
		 	goto again;
	 else if (n<0) 
   ERR
}


