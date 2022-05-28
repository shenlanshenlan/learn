//并发服务器

#include "k.h"
struct sockaddr addr;
struct sockaddr accaddr;
socklen_t acclen;

int lsfd;
int accfd;
int n;
int main()
{
	lsfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	create_IP4_2("192.168.1.103", 9810, &addr);

	if ((bind(lsfd, (SA *)&addr, sizeof(addr))) != 0)
	{
		printf("listen error\n");
		exit(0);
	}

	if ((listen(lsfd, 20)) != 0) // 可能timewait
	{
		printf("listen error\n");
	}
	accfd = accept(lsfd, &accaddr, &acclen);

 	//echo_1(accfd);   // use API sleect;
      echo_2(accfd);   // use poll
	close(lsfd);
	cout("socker close");
	sleep(1);
}
