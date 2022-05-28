// 设计范式 测试客户端

#include "k.h"
#define BUF_NAME 20;

int main(int argc, char **argv)
{
  char   *dsthost  = "192.168.1.101";
  char   *serv     = "9810";
  char   *request = "这里是测试数据,请求！";
  char    reply[200];
  int reqs = 1;    //请求次数;
  int process = 1; //进程数;          
  int nbetys = 100;  // 请求字节数;
  pid_t pid; 
  int   n; 




  int fd;
  int i = 0;
  int j = 0;
  for (; i < process; i++)
  {   
    if ((pid = fork()) == 0) //子进程
    {   
      for (; j < reqs; j++)
      {  
        fd = create_sock(dsthost, serv);
        if (fd < 0) 
         {   //printf("%d\n",fd);
            exit(0);
         }
        /*cout("dd");
         write(fd,request,strlen(request));
         if(( n = read(fd,reply,nbetys)) != nbetys) 
         printf("返回的字节个数错误\n");*/
        


         close(fd);

      }
    
      printf("child : %d\n", i); 
      exit(0);
    }                     
       //printf("pid : %d\n", pid); 
  }
     wait(NULL);
 exit (0);  
}  