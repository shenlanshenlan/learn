// 路由套接字

#include "k.h"
#include  <net/route.h>
#define   BUFLEN   (sizeof(struct rt_msghdr) + 512)
#include  <net/if_dl.h>

int main(int argc , char **argv){
  int sockfd;
  struct rt_msghdr *rtm;   //消息结构
  char   *buf;
  struct sockaddr_in  *sin; //IPv4地址结构


  sockfd = socket(AF_ROUTE,SOCK_RAW,0);
  //初始化消息结构
    buf = calloc(1,BUFLEN);    //申请内存空间
    rtm = (struct rt_msghdr*)buf;
    rtm->rtm_msglen = sizeof(struct rt_msghdr)+sizeof(struct sockaddr_in);//消息长度
    rtm->rtm_version = RTM_VERSION;       //版本
    rtm->rtm_type = RTM_GET;              //消息类型
    rtm->rtm_addrs=RTA_DST;               //地址结构用途  此处为目的地
    rtm->rtm_pid = getpid();
    rtm->rtm_seq = SEQ;
    
    sin = (struct sockaddr_in*)(rtm+1);  //IPv4 地址结构 初始化

    sin->sin_len = sizeof(struct sockaddr_in);
    sin->sin_family = AF_INET;
    inet_pton(AF_INET,argv[1],&sin->sin_addr); 
    
    write(sockfd,rtm,rtm->msglen);   //写入路由套接字
         






 
  









 return (0);
}