// 多播接受端
#include "k.h"

int main(){
    int  sockfd;
    socklen_t  n;
    struct  sockaddr_in   recaddr;
     struct sockaddr      *recvaddr;
    char   recline[MAX];

    //初始化地址结构
    memset(&recaddr,0,sizeof(recaddr));
    recaddr.sin_family = AF_INET;
    recaddr.sin_port   = htons(2254);
    recaddr.sin_addr.s_addr=htonl(INADDR_ANY);
 
      
     //  inet_pton(AF_INET,"192.168.1.102",&recaddr.sin_addr.s_addr);
       //recaddr.sin_addr.s_addr  =  htonl(recaddr.sin_addr.s_addr);


    sockfd = socket(AF_INET,SOCK_DGRAM,0);
        int as= bind(sockfd,(SA *)&recaddr,sizeof(recaddr));
    //加入广播

    struct ip_mreq join_adr;                         //多播设置结构
       struct in_addr s;          
       inet_pton(AF_INET,"224.1.1.2",&s);            //地址转换 
         
         int  aa;
      
    join_adr.imr_multiaddr  = s ;                    //广播地址
    join_adr.imr_interface  = recaddr.sin_addr;      //本地接口地址
      aa =  setsockopt(sockfd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&join_adr,
              sizeof(join_adr));                     //加入多播放组
              if(aa!=0)
              ERR

    for( ; ; )
    {   
        n= sizeof(recvaddr);
         recvfrom(sockfd,recline,MAX,0,recvaddr,&n);
         
     
         write(1,recline,strlen(recline));

    }
}