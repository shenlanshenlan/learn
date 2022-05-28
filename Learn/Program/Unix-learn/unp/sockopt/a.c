//套接字设置
#include "k.h"


int
main() 
{ int  flag;
	int  fd;
	socklen_t  ss;
fd=	socket(AF_INET,SOCK_STREAM,0);
 if(fd < 0 )
 { ERR}
	else 
{	OK}
printf("%d\n",fd);

 	getsockopt(fd,SOL_SOCKET,SO_BROADCAST,&flag,&ss); //获取广播设置
	 
	 printf("%d\n",flag);  //输出设置





exit(0);
}
