// tcp图片接受

#include "k.h"
struct sockaddr addr;
struct sockaddr accaddr;
socklen_t acclen;
int lsfd;
int accfd;
int n;
int sum = 0;
char accbuf[100000];

pid_t childpid;

int main()
{
	lsfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	create_IP4_2("127.0.0.1", 9810, &addr);
	bind(lsfd, (SA *)&addr, sizeof(addr));
	if ((listen(lsfd, 10000)) < 0)
	{
		printf("listrn error\n");
		exit(0);
	}

	for (;;)
	{
		sum += 1;
		accfd = accept(lsfd, &accaddr, &acclen); //获取链接

		if ((childpid = fork()) == 0) //子进程
		{
			cout(k_ntop(&accaddr)); //打印对方地址
			close(lsfd);
			n = read(accfd, accbuf, 100000);
			printf("从客户端(%d) 读取到%d个字符。\n", sum, n);
			close(accfd);
			exit(0);
		}
		//父进程
		close(accfd); //关闭链接描述符
		if (sum > 10000)
			break;
	}

	printf("sum:%d   server off\n", sum);
}
