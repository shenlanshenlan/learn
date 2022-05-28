//时间客户端程序
#include  "include.h"
#define  MAX  30
int main(int argc, char **argv)
{
 	int						sockfd,n;
	char					recvline[MAX+1];
	struct				sockaddr_in servaddr; //IPV4地址


	if(argc!=2)
	printf("参数错误\n"); 

	if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
	   printf("创建套接字失败");
	
	servaddr.sin_family =AF_INET;
	servaddr.sin_port = htons(13);
	if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0)
	 printf("地址设置错误\n");  //获取命令行地址

	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
	{ printf("建立连接失败\n"); //建立连接
	  close(sockfd);
	  exit(0);

 }
 else
	  OK
while((n = read(sockfd,recvline,MAX))>0)  //读取字符串
		{  
		  recvline[n]=0;
			if(fputs(recvline,stdout)==EOF)  //输出字符串
			ERR
	}
			if (n<0)
			ERR    
			close(sockfd);
			exit(0);
}
