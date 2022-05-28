//traceroute   路由追踪
//因未知原因  可能由于路由器阻拦UDP返回的ICMP  此程序阻塞于  recvfrom 
//问题1： 设置的定时器并未解除 阻塞
//问题2： 通过TCPDUMP 观察发送的UDP数据包并未返回ICMP 消息
// 于2017.8.22
#include "t.h"
#include "k.h"
#include "tf.c"
int 
main(int argc,char **argv){
 if(argc<2)
{
  cout("缺少地址参数");
  exit(0);
}
 pid = getpid(); 

 u_short dport = 1000 + 0;
         nprobes = 3;
 ai = host_serv(argv[1],NULL,0,0);//获取主机地址

 sasend = ai->ai_addr;
 sarecv = calloc(1,sizeof(ai->ai_addrlen));
 salast = calloc(1,sizeof(ai->ai_addrlen));
 sabind = calloc(1,sizeof(ai->ai_addrlen));
 salen  = ai->ai_addrlen;
 
printf("%s\n",k_ntop(sasend));
 
 if((sockraw = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP))<0) 
    {
      cout("原始套接字创建失败");
      exit(0);
    }
 if((sockudp = socket(AF_INET,SOCK_DGRAM,0))<0) 
    {
      cout("UDP套接字创建失败");
      exit(0);
    }

    sabind->sa_family = sasend->sa_family;
    sport = (pid&0xffff)|0x8000;
    sock_set_port(sabind,sport);
     int o = bind(sockudp,sabind,salen);
    printf("%s\n",k_ntop(sabind));
    signal(SIGALRM,sig_alrm);
    
    

   // sig_alrm(SIGALRM);

    seq = 0;
    done = 0;

     
for(ttl = 1;ttl <=max_ttl&&done == 0;ttl++)
 {  
    setsockopt(sockudp,IPPROTO_IP,IP_TTL,&ttl,sizeof(int));
    //设置 IP TTL 选项
    memset(salast,0,salen);   //初始化 salast 地址
      
     printf("%4d\n",ttl); 
    
     fflush(stdout); //冲洗缓冲区
     //初始化发送缓冲区

     for(probe=0;probe<nprobes;probe++)  //内层循环3次
    {
    rec = (struct rec *)sendbuf;
    rec->rec_seq = ++seq;
    rec->rec_ttl = ttl;
    gettimeofday(&rec->rec_tv,NULL);
    
    sock_set_port(sasend, htons(dport+seq));
    //此处设置了 sasend 的端口号
    sendto(sockudp,sendbuf,sizeof(struct rec),0,sasend,salen);
    printf("udp len :%d\n",sizeof(struct rec));
    if(code = recv_v4(seq,&tvrecv) == -3)  //调用recv_v4
    {
       printf("timeout no reply\n");
    } else {
       char  str[500];
       if(sock_cmp_addr(sarecv,salast,salen)!=0)
          {  if(getnameinfo(sarecv,salen,str,sizeof(str),NULL,0,0) == 0)
              printf("%s(%s)",str,k_ntop(sarecv));
              else 
              printf( "%s",k_ntop(sarecv));
              memcpy(salast,sarecv,salen);
            }
        tv_sub(&tvrecv,&rec->rec_tv);
        rtt = tvrecv.tv_sec * 1000.0 + tvrecv.tv_usec / 1000.0;
        printf("%.3f ms",rtt);

        if(code == -1)
           done++;
        else if(code >= 0)
          printf("(icmp error:%d)",code);
    } 
     fflush(stdout);
   }      
   printf("\n");
  }

 
 exit(0);
}
