//udp 回射服务器程序

#include "k.h"
#include "fun.c"

int main()
{
	 int sockfd;
	 struct sockaddr_in servaddr,cliaddr;

	 sockfd=socket(AF_INET,SOCK_DGRAM,0);
   
	 memset(&servaddr,0,sizeof(servaddr));//初始化地址
	 servaddr.sin_family=AF_INET;					
	 servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	 servaddr.sin_port = htons(2254);
	 //创建地址结构
	 bind(sockfd,(SA *)&servaddr,sizeof(servaddr));
   //绑套接字
	 dg_echo(sockfd,(SA *)&servaddr,sizeof(cliaddr));
}  //带入参数1 套接字。2地址结构。3长度
