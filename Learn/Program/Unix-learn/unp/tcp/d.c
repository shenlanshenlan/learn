// 修订版6-21
#include "include.h"

int main(int argc,char **argv)
{
	int i,maxi,maxfd,listenfd,connfd,sockfd;
	int	nready,client[FD_SETSIZE];
	ssize_t			 n;
	fd_set			 rset,allset;
	char 				 buf[MAX];									
	socklen_t		 clilen;
	struct sockaddr_in cliaddr,servaddr;

	listenfd = socket(AF_INET,SOCK_STREAM,0);//创建套接字

	memset(&servaddr,0,sizeof(servaddr));    //初始化地址结构
	servaddr.sin_family = AF_INET;					 //设置协议族
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//设置地址
	servaddr.sin_port = htons(SERV_PORT); 	 // 设置端口号

	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
  //绑定套接字
	listen(listenfd,30);
  //监听
	maxfd = listenfd;
	maxi  = -1;
	for ( i = 0;i<FD_SETSIZE;i++)  //循环最大描述符集
			client[i] = -1;            //循环设置为-1
			FD_ZERO(&allset);    			//初始化描述符集
		 for( ; ; )
	{
		 rset = allset;
		 nready =select(maxfd+1,&rset,NULL,NULL,NULL);//调用select
		 //返回就绪的描述符个数

		 if(FD_ISSET(listenfd,&rset))
	{	 clilen = sizeof(cliaddr);
		 connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&clilen);
     //得到连接的描述符
		 for(i =0 ;i <FD_SETSIZE;i++)
		 		if(client[i]<0)
				{
					client[i]=connfd;
					break;
									}
			if(i==FD_SETSIZE)
		 	 	 ERR
		FD_SET(connfd,&allset);
		 if(connfd>maxfd)
		 		maxfd=connfd;
				if(i > maxi)
				maxi = i;
			if(--nready<=0)
			   continue;
	 }
			for(i = 0; i<=maxi;i++)
		{		if((sockfd = client[i])<0)
				continue;
			if(FD_ISSET(sockfd,&rset))
			{   if((n=read(sockfd,buf,MAX))==0)
				close(sockfd);
				FD_CLR(sockfd,&allset);
				client[i] = -1;
				}else
				{
				  write(sockfd,buf,n);
					if(--nready<=0)
					break;
				}
			}
		}
} 



	//		FS_SET(listenfd,&allset);





