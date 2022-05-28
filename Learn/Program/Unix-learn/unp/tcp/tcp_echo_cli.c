// 客户端程序
#include "k.h"
void str_cli(FILE *fp,int sockfd);


int main(int argc,char **argv)

{
	int sockfd;
	struct sockaddr_in servaddr;
	if (argc !=2)
		ERR
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   =htons(9999);
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

	connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

	str_cli(stdin,sockfd);
	
	exit(0);
}

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



