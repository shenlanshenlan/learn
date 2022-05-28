//  tf.c
// 函数定义
#ifndef _TF_C
#define _TF_C

#include "k.h"
//#include "t.h" 

extern  int   gotalarm;
void sig_alrm(int signo)
{   
    gotalarm = 1;
    printf("function of sig_alrm\n");
    return;
}

int recv_v4(int seq,struct timeval *tv )
{   /* 返回状态
             -3  未响应
             -2  超时被丢弃
             -1  不可达（到达目的地，但是端口无效）
             <=0 其他icmp 错误
   */


    // 局部变量
 extern  socklen_t salen;
         socklen_t len;
         ssize_t   n;
int   hlen1,hlen2,icmplen,ret;
struct ip   *ip,*hip ;
struct icmp *icmp;
struct udphdr *udp;


    gotalarm = 0 ;  //设置此变量为零
    alarm(3);      //设定3妙定时 如果超过三妙gotalarm值将为1
 
  for( ; ; )

 {      
    if(gotalarm==1)
    return (-3);      //3s未相应
    
    len = salen;  
 
    
n = recvfrom(sockraw,recvbuf,sizeof(recvbuf),0,sarecv,&len);
 
//参数1套接字2接受缓冲3长度4？？5返回地址6地址长度     
    if(n<0)  //如果接受到的数据为0,
     {  continue;
     }
//解析返回IP数据报
    ip = (struct ip *)recvbuf;
    hlen1 = ip->ip_hl<<2;  
    icmp  = (struct icmp*)(recvbuf + hlen1);
  if((icmplen = n - hlen1)<8) //icmp首部长度不够
     continue;
//如果icmp 消息    超时
    if(icmp->icmp_type == ICMP_TIMXCEED &&
       icmp->icmp_code == ICMP_TIMXCEED_INTRANS)
    {
     if(icmplen < 8 + sizeof(struct ip))
        continue;//判断icmplen 长度
        //icmp长度 应该为 产生差错报文的IP首部和至少8字节的UDP首部
        
        hip = (struct ip *)(recvbuf + hlen1 + 8); //产生差错报文的IP首部
        hlen2 = hip->ip_hl<<2; //差错IP 首部长度
     
    if(icmplen < 8 +hlen2 +4)
        continue;  //判断该icmp 是否包含 udp 
                  
    udp = (struct udphdr * )(recvbuf + hlen1 +8 +hlen2);
    //获取UDP 首部指针
    
    if(hip->ip_p == IPPROTO_UDP &&
       udp->uh_sport == htons(sport)&&
       udp->uh_dport == htons(dport+seq))
       ret = -2;
       break;
    } else if (icmp->icmp_type == ICMP_UNREACH) //目标不可达
     {   
        if(icmplen < 8 + sizeof(struct ip))
        continue;//判断icmplen 长度
        //icmp长度 应该为 产生差错报文的IP首部和至少8字节的UDP首部
        
        hip = (struct ip *)(recvbuf + hlen1 + 8); //产生差错报文的IP首部
        hlen2 = hip->ip_hl<<2; //差错IP 首部长度
        if(icmplen < 8 +hlen2 +4)
        continue;  //判断该icmp 是否包含 udp     

        udp = (struct udphdr * )(recvbuf + hlen1 +8 +hlen2);
        //获取UDP 首部指针
        if(hip->ip_p == IPPROTO_UDP &&
            udp->uh_sport == htons(sport)&&
            udp->uh_dport == htons(dport+seq))
         {
            if(icmp->icmp_code == ICMP_UNREACH_PORT)
              {

              ret = -1;
              }else{ 
               ret = icmp->icmp_code;
              }
               break;
         }
      }


      
    }
 
       alarm(0); //阻止定时器信号
       gettimeofday(tv,NULL);
       return(ret);
}




#endif