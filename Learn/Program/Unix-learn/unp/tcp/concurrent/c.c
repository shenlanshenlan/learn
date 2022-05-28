//tcp图片发送

#include "k.h"

char *desname = "127.0.0.1";

int port = 9810;
char msg[10000];
int fd;
int n;
struct sockaddr desaddr;
socklen_t len = sizeof(desaddr);

int req  ;
int i;
int filefd;
pid_t childpid;
int main(int argc ,char **argv)
{
  req = atoi(argv[1]);
  create_IP4_2(desname, 9810, &desaddr);

  for (i = 0; i < req; i++)
  {

    if ((childpid =  fork()) == 0) //子进程
    {
      fd = tcp_connect(&desaddr);
      filefd = open("/home/k/jpg/a.jpg",O_RDONLY);
      n = read( filefd ,msg,10000);
      write(fd,msg,n);
      
      printf("传送%d字符完毕，关闭子进程%d\n",n,getpid());
      close(fd);
      exit(2);
    }
  }            
 ID
 int childstat ;
 wait(&childstat);
 
 printf("关闭父进程\n");
 exit(0);
}