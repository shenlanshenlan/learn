//unix域协议

#include "/home/k/include/include.h"
#define  UNIXSTR_PATH  "/tmp/unix.str"
int
main(int argc , char argv[])
{
        int listenfd,connfd;  //监听套接字   连接的套接字
		  	pid_t    childpid ;  //子进程id
	  		socklen_t    len   ;  //套接字长度
struct	sockaddr_un  cliaddr,servaddr;//套级字地址 客户  服务器
				char str[100];
				
				void sig_child(){
				
				}

				listenfd = socket(AF_LOCAL,SOCK_STREAM,0);//创建套接字
				
				unlink(UNIXSTR_PATH);

				memset(&servaddr,0,sizeof(servaddr));
				servaddr.sun_family = AF_LOCAL;
				strcpy(servaddr.sun_path,UNIXSTR_PATH);

				bind(listenfd,(SA *)&servaddr,sizeof(servaddr));//绑定套接字

				listen(listenfd,30);

				signal(SIGCHLD,sig_child);  //设置信号及处理程序

				for( ;  ; )
			{ len =sizeof(cliaddr);
				
				if((connfd = accept(listenfd,(SA *)&cliaddr,&len))<0)
				 continue;
		
			if((childpid = fork())== 0)  //子进程空间
		  {     close(listenfd);
				 int n;
		  for( ; ;)
		{	
		  	   n= read(connfd,str,100);        //读取信息
				   printf("%d:",n);
           write(connfd,str,n);						//回射信息
					 printf("%s\n",str);
			}
		}	
		close(connfd);    //父进程关闭套接字
	}
}










				

   





