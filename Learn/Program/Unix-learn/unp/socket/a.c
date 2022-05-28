//  socket 演示程序


#include "include.h"
#include <time.h>
//#include <string.h>
#define   MAX     30 
int main()
{   char   *kk="hellow world";
    int             listenfd,connfd;
    socklen_t        len;
    struct sockaddr_in servadd,cliadd;
    char            buff[MAX];
    time_t          ticks;

    listenfd = socket(AF_INET,SOCK_STREAM,0);    //创建套接字 
    if(listenfd<0)
      {  printf("套接字创建失败");  }
   // bzero(&servadd,sizeof(servadd));  //初始化地址;

    servadd.sin_family = AF_INET;                    //设置协议族
    servadd.sin_addr.s_addr = htonl(INADDR_ANY);    
     //设置地址其中INADDR_ANY为本机地址信息，htonl 大小序转换
    servadd.sin_port = htons(13);     //设置端口号
          int w;
          if((w=bind(listenfd,(struct sockaddr *)&servadd,sizeof(servadd))) !=0)   //帮顶套接字和地址
          {
           printf("bind err :%d\n",w);
           close(listenfd);
           exit(0) ;
          }
        if((listen(listenfd,10)<0))  //监听端口
         ERR
    OK   printf("由此阻塞\n");    
     
     for( ; ; )
{   len = sizeof(cliadd);
    connfd = accept(listenfd,(struct sockaddr *)&cliadd,&len);
    //int q= printf("connection form %s , port, %d\n",
         //   inet_ntop(AF_INET,&cliadd.sin_addr,buff,sizeof(buff)),  //地址转换
          //  ntohs(cliadd.sin_port));                                // 字节序转换
   /* if (q==0)
        OK
        else 
        ERR    */
    //ticks = time(NULL);   
   // snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
    write(connfd,kk,sizeof(buff));   // 向套接字中写入  hello world
    close(connfd); 
     
}


     
return 0;

}
