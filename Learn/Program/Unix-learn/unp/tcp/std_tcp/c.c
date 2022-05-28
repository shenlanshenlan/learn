//tcp图片发送 

#include "k.h"

char *desname = "192.168.1.101";

int port = 9810; 
char msg[100];
int fd;
int n;
struct sockaddr       desaddr;
socklen_t len = sizeof(desaddr);

int main()
{
  fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  create_IP4_2(desname,9810,&desaddr); 
  connect(fd,&desaddr,32);
   
    







 
  close(fd);
}
