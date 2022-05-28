//并发服务器

#include "k.h"

char *desname = "192.168.1.103";

int port = 9810;
char msg[100];
int fd;
int n;
struct sockaddr desaddr;
socklen_t len = sizeof(desaddr);

int process = 10;

int main()
{
  fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  create_IP4_2(desname, 9810, &desaddr);
  n = connect(fd, &desaddr, 32);

  if (n < 0)
  {
    printf("链接失败\n");
    exit(0);
  }

  //echo_1(fd);  //use API select;
  echo_2(fd);    //use poll
  close(fd);
  cout("socker close");
  sleep(1);
} 