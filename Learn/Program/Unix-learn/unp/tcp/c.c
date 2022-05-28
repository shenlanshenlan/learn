// 同时创建5个连接 客户端

#include "include.h"
void str_cli(FILE *fd, int sockfd)
{
 	char sendline[MAX],recvline[MAX];
	 
	 while(fgets(sendline,MAX,fd)!=NULL)
	 {   write(sockfd,sendline,strlen(sendline));
	 	if(read(sockfd,recvline,MAX) == 0)
		   ERR
		fputs(recvline,stdout);
		}
	}


int main(int argc , char **argv ) 
{  int i,sockfd[5];
	 struct sockaddr_in servaddr;
if(argc!=2)
	{
	ERR
	}
for(i=0;i<5;i++)
{		OK
		sockfd[i]=socket(AF_INET,SOCK_STREAM,0);
		memset(&servaddr,0,sizeof(servaddr));
		servaddr.sin_family=AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

		connect(sockfd[i],(struct sockaddr *)&servaddr,sizeof(servaddr));
  OK
}
		str_cli(stdin,sockfd[0]);
		exit(0);
}
