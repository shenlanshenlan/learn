// tcp图片接受

#include "k.h"
struct sockaddr      addr;
struct sockaddr      accaddr;
socklen_t acclen;
 
 
int lsfd;
int accfd;
 
 
int main()
{
	lsfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    create_IP4_2("192.168.1.101",9810,&addr);
	bind(lsfd, (SA *)&addr, sizeof(addr));
	listen(lsfd,20);
  
	sleep(10);
  
 
 
	close(lsfd);
}
