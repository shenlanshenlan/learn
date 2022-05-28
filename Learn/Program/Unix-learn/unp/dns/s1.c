//  s1 tcp
// getaddrinfo  第一个参数为零的话  返回 缺省地址0.0.0.0 
// 等同于 INADDR_ANY  默认的本机地址



#include "include.h"
#include "fun.c"
char * sock_ntop(const struct sockaddr *sa,socklen_t salen)
{	
	char portstr[8];
	static char str[128];
 	   switch(sa->sa_family)
		 case AF_INET:
		 {  struct sockaddr_in *sin = (struct sockaddr_in *)sa;
		    //指针转换
 	inet_ntop(AF_INET,&sin->sin_addr,str,sizeof(str));
				
				

				}
	return (str);

	}
				





int 
main(int argc, char **argv)
{
 	int					 listenfd,connfd; //存储本机套接字和连接的套接字
	socklen_t 	 len;
	char  			 buff[MAX];
	time_t			 ticks;
	struct sockaddr_storage  cliaddr;  //系统中最大的地址结构
  
	if(argc!=2)
	  ERR
  listenfd = tcp_listen(NULL,argv[1],NULL);

	for( ;  ;)
 { 
     len = sizeof(cliaddr);
		 connfd = accept(listenfd,(SA *)&cliaddr,&len);//获取连接

		 printf("connection from %s\n",sock_ntop((SA*)&cliaddr,len));  //   打印连接IP地址
    
		ticks = time(NULL);
		snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));

	  write(connfd,buff,strlen(buff));
		close(connfd);
	}
}
