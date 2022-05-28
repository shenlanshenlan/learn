//获取接口列表 ioctl
#include "k.h"
#include <unistd.h>
int main() 
{ 
   int sockfd;
	 int len;                 //缓冲区长度
   char *buf;               //缓冲去指针
   int si;                  //用以存储得到的ifreq个数
   struct ifconf   k_ifconf;
   struct ifreq   *k_ifreq ,k_flags ;
   char *savebuf;           //存储缓冲区指针  以释放内存  
   struct sockaddr_in    *hostaddr; 
   char   addr_name[30];
  //初始化结构
  len = 100*sizeof(struct ifreq);
	buf = malloc(len);
  k_ifconf.ifc_len = len;
	k_ifconf.ifc_buf = buf;
  //创建套接字
   sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
   printf("套接字描述符%d\n",sockfd);
	  
   ioctl(sockfd,SIOCGIFCONF, &k_ifconf);  //获取接口列表
  	//用ifconf的长度除以 ifreq长度 得到  req 个数;
   savebuf = buf;                         //保存指针
	 si = k_ifconf.ifc_len/sizeof(struct ifreq) ;
   printf("获取的req结构个数是：%d\n",si);

   struct ifreq *uu = (struct ifreq *)buf;     //类型转换

      int i=0;   for(;i<si; i++)   
	{	    printf("接口%d\n",i);
        printf("name: %s\n",uu->ifr_name); //    输出网卡名字 
        
        hostaddr = (struct sockaddr_in*)&(uu->ifr_addr);   //地址转换
        inet_ntop(AF_INET,&(hostaddr->sin_addr.s_addr),addr_name,30);   //名称转换                    
        printf("IPv4 addr: %s\n",addr_name);  //输出IPv4 地址 

        k_flags  = *uu;

        ioctl(sockfd,SIOCGIFFLAGS,&k_flags ) ;  //flags
        printf("flags: %d\n",k_flags.ifr_flags);
 
        ioctl(sockfd,SIOCGIFMTU,&k_flags ) ;  //mtu
        printf("MTU: %d\n",k_flags.ifr_mtu);
      
        if(ioctl(sockfd,SIOCGIFMETRIC,&k_flags )<0)    //metric
          ERR
        else  printf("metric: %d\n",k_flags.ifr_metric);

        if(ioctl(sockfd,SIOCGIFDSTADDR,&k_flags)<0)       // addr
           ERR
       else{  hostaddr = (struct sockaddr_in*)&(k_flags.ifr_dstaddr);
        inet_ntop(AF_INET,&(hostaddr->sin_addr.s_addr),addr_name,30);
        printf("DST addr: %s\n",addr_name);  //输出IPv4 地址 
       }

   uu++;

   }
 






  free(savebuf);      //释放内存
 
  return(0);
}
