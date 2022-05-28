//UDP 客户端程序

#include "include.h"
#include "fun.c"
int
main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;
	argv[1]="127.0.0.1";
//	if(argc != 2)
	  //ERR
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
	
	sockfd = socket(AF_INET,SOCK_DGRAM,0);

	dg_cli(stdin,sockfd,(SA *)&servaddr,sizeof(servaddr));
	exit(0);
}
