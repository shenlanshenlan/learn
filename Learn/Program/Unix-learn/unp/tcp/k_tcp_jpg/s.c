// tcp图片接受

#include "k.h"

struct sockaddr_in addr;
struct sockaddr accaddr;
socklen_t acclen;
char msg[100];
char jpg[70000];
int lsfd;
int accfd;
int n;
int file_fd;
int sum = 0;
int main()
{
	lsfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	addr.sin_port = htons(9810);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(lsfd, (SA *)&addr, sizeof(addr));
	listen(lsfd,20);
	file_fd = open("/home/k/jpg/22.jpg", O_CREAT);
	printf("%d\n", file_fd);
  file_fd = open("/home/k/jpg/22.jpg", O_WRONLY);
	printf("%d\n", file_fd);
	
 // tcp 分多次接受到数据，write也一样分多次写入文件 
	int i;
	for (i = 0; i < 1; i++) 
	{
		accfd = accept(lsfd, &accaddr, &acclen);
		cout(k_ntop(&accaddr));
		for (;;)
		{
			n = read(accfd, jpg, 700000); //read msg
			if (n == 0)
				break;
			sum += n;
			printf("%d\n", sum);

			write(file_fd, jpg, n);
		}
	}
	close(lsfd);
}
