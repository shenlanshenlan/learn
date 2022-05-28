//tcp图片发送 

#include "k.h"

char *desname = "192.168.1.101";
char reqbuf[10];
int port = 9810;
int fd;
int file_fd;
char msg[100];
char jpg[700000];
int n;
struct sockaddr_in desaddr;
socklen_t len = sizeof(desaddr);

int main()
{
  fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  //通讯建立
  desaddr.sin_family = AF_INET;
  desaddr.sin_port = htons(port);
  inet_pton(AF_INET, desname, &desaddr.sin_addr);
  connect(fd, (SA *)&desaddr, len);

  //读取 文件

  file_fd= open("/home/k/jpg/a.jpg", O_RDONLY);
  n = read(file_fd, jpg, 700000);
  printf("%d\n",n);
  write( fd, jpg, n);
  sleep(10);
  close(fd);
}
