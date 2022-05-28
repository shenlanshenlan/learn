// udp 多播放发送端

#include "k.h"

 

int 
main()
{  int sockfd; 
	char   readlin[MAX];	


    
	struct	 sockaddr_in send;
         
memset(&send,0,sizeof(send)); //初始化套接子地址结构
send.sin_family = AF_INET;
send.sin_port   = htons(2254);
inet_pton(AF_INET,"224.1.1.2",&send.sin_addr.s_addr);  //目标地址为多播地址

sockfd = socket(AF_INET,SOCK_DGRAM,0);  //创建套接字

while(fgets(readlin,MAX,stdin)!=NULL)
  {            
           //  printf("%s\n",readlin);
	  sendto(sockfd,readlin,strlen(readlin),0,(SA *)&send,sizeof(send));
	 
  }

}

 
