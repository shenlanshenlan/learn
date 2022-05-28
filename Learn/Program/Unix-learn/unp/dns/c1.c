//时间获取 客户程序

#include "fun.c"

int main(int argc , char **argv)
{
	int sockfd,n;
	char recvline[MAX+1];
	socklen_t len;
	struct sockaddr_storage ss;

	if(argc!=3)
	  ERR

		sockfd = tcp_connect(argv[1],argv[2]);

		len = sizeof(ss);

		getpeername(sockfd,(SA*)&ss,&len);
		
		while ((n=read(sockfd,recvline,MAX))>0){
		recvline[n] = 0;
		fputs(recvline,stdout);
		}
		exit(0);
	}
