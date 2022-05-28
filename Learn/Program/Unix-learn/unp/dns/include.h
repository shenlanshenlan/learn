#include <stdio.h>        //输入输出
#include <sys/wait.h>     //进程等待
#include <stdlib.h>       //
#include <sys/stat.h>     //文件结构stat
#include <unistd.h>       //文件权限access
#include <setjmp.h>   	  //跳转
#include <time.h> 		  //时间
#include <pthread.h>      //线程
#include <fcntl.h>        //标准IO
#include <string.h>
//socket UNP
#include <netdb.h>				//网络
#include <sys/socket.h>   //套接字
#include <netinet/in.h>
#define MAX 4096
#define SA  struct sockaddr     //通用地址结构用于地址转换
#define SERV_PORT  9877
//#define bzero(ptr,n)  memset(ptr,0,n)
#define max(a,b)  ((a)>(b)?(a):(b))
#define ERR { printf("error\n");exit(0);}
#define OK  printf("ok\n");
#define S1  printf("this s1\n");
#define S2  printf("this s2\n");

/*   void Stime()
{   struct timespec tout;
    struct tm       *tmp;
    char          buf[64];
    
     clock_gettime(CLOCK_REALTIME,&tout);
     tmp=localtime(&tout.tv_sec);
     strftime(buf,sizeof(buf),"%r",tmp);
     printf("get time at:%s\n",buf);
}
 */
