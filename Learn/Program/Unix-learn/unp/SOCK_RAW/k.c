// 原始套接字  ping 程序

#define BUFSIZE 1500
#include "k.h"
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include "/home/k/include/fun.c"
// 变量
struct 	  sockaddr   *send_addr,*recvaddr;
pid_t  				 pid;
struct 	  addrinfo   *ai;
int   				 sockfd;
int   				 n;
int   			     datalen=56;
int 			     nsent;
char                 sendbuf[BUFSIZE];
char                 recvbuf[BUFSIZE];
char                 controlbuf[BUFSIZE];
struct     msghdr    msg; 
struct     iovec     iov;




// 函数定义
struct addrinfo* //该函数获取主机名参数，返回addrinfo结构
host_serv(char* hostname,char * serv,int  family,int socktype);
 
void send_v4(void); //该函数初始化ICMP数据报 并发送

void sig_alrm(int);//定时发送消息
 
void show_revc_msg(int sockfd);

void fproc(char *recvbuf,ssize_t n,struct msghdr *msg,struct timeval *tvrecv);

void tv_sub(struct timeval *out,struct timeval *in);


//主函数
int main(int argc,char **argv){
	
	pid = getpid()&0xffff;
	sockfd = socket(AF_INET,SOCK_RAW,1);  //创建原始套接字

    ai= host_serv(argv[1],NULL,AF_INET,0);//获取addrinfo
 
	signal(SIGALRM,sig_alrm); //设置消息处理函数
	sig_alrm(SIGALRM);               //发送消息
    recvaddr = calloc(1,sizeof(ai->ai_addrlen));
   char  buf[MAX];
  if(sockfd<0)
	 ERR
	 OK;
     show_revc_msg(sockfd);  //显示返回信息

}  


//～～～～～～～～～～～～相关函数～～～～～～～～～～～～～～～～～～～
//～～～～～～～～～～～～相关函数～～～～～～～～～～～～～～～～～～～
//～～～～～～～～～～～～相关函数～～～～～～～～～～～～～～～～～～～
struct addrinfo* 
host_serv(char* hostname,char * serv,int  family,int socktype)
{      
	   int n; 
		struct addrinfo hit,*res;
		  hit.ai_flags  = AI_CANONNAME;
		  hit.ai_family = family;
		  hit.ai_socktype = socktype;         
	if((getaddrinfo(hostname,serv,&hit,&res))!=0)
	 {   printf("地址未找到\n");
		 return (NULL); 
		 exit(0);
	}      
	return(res);
}

uint16_t 
in_cksum(uint16_t *addr,int len)
{  int nleft = len;
   uint32_t  sum = 0;
   uint16_t   *w = addr;
   uint16_t   answer = 0;
   
   while (nleft>1)
   {  
	sum+=*w++;
	nleft -=2;
   }
    if(nleft = 1){
		*(unsigned char*)(&answer) = *(unsigned char *)w;
	 	sum+=answer;
	}
	sum = (sum >> 16) + (sum & 0xffff);
	sum +=(sum >> 16);
	answer = ~sum;
	return  answer ;
}

 
void send_v4(void)
{
 struct icmp  *icmp;
 int            len;
 send_addr = ai->ai_addr;
 
icmp =(struct icmp*)sendbuf; // 初始化icmp 内存空间
icmp->icmp_code =0;
icmp->icmp_type = ICMP_ECHO;
icmp->icmp_id   = pid;
icmp->icmp_seq  = nsent++;
 
memset(icmp->icmp_data,0xa5,datalen);
gettimeofday((struct timeval *)icmp->icmp_data,NULL);

len = 8+datalen;
icmp->icmp_cksum = 0;
icmp->icmp_cksum = in_cksum((u_short *)icmp,len);

if((sendto(sockfd,icmp,len,0,send_addr,ai->ai_addrlen)<0))
  printf("send icmp error\n");
}

void sig_alrm(int signo)
{  
	  send_v4();
	  alarm(1);
return;
}

 void show_revc_msg(int sockfd)
{  
     struct  timeval  tval;
	 ssize_t   n;
	// 初始化  msghdr 结构
	iov.iov_base =  recvbuf;
	iov.iov_len  =  sizeof(recvbuf);
	msg.msg_name =  recvaddr;
	msg.msg_iov      =&iov;
	msg.msg_iovlen   = 1;
	msg.msg_control  = controlbuf;
	
	for( ; ; )
{     msg.msg_namelen = ai->ai_addrlen;
	  msg.msg_controllen = sizeof(controlbuf);
	
	 n=recvmsg(sockfd,&msg,0);    //n为返回字节数
	 if(n<0)
	   {   printf("未响应\n");
	       exit(0);
   }else{
	 gettimeofday(&tval,NULL); 
     fproc(recvbuf,n,&msg,&tval); 
    }
   }
}

void fproc(char *recvbuf,ssize_t len,struct msghdr *msg,struct timeval *tvrecv)
{  
	struct  icmp *icmp; 
	struct  ip   *ip;
	int     ip_heard_len;
	int     icmplen;
	struct   timeval *tvsend;
    double   rtt;
    char     *p_addr;
	ip = (struct  ip *)recvbuf;
	ip_heard_len = ip->ip_hl<<2; 
	/*获取ip 首部指针长度,其中位移运算指示其值*4
	ip_hl的值为占用32bit的个数，无ip选项的话其值为5 所以 5*4 = 20个字节;*/

	icmp = (struct icmp*)(recvbuf+ip_heard_len);//获取iccmp首部
	   if( ( icmplen =len - ip_heard_len) < 8)
		 return ;          //
	
	if(icmp->icmp_type == ICMP_ECHOREPLY)
    { 
		   if(icmp->icmp_id!=pid) 
		   return;     
		   if( icmplen<16)
		   return;
	  tvsend = (struct timeval*)icmp->icmp_data;
	  tv_sub(tvrecv,tvsend); //时间处理
      
	  rtt = tvrecv->tv_sec*1000.0+tvrecv->tv_usec/1000.0;
	  
	printf("%d bytes from %s: seq=%u, ttl=%d,rtt=%f, ms\n",
	   icmplen,
	   k_ntop( msg->msg_name),
	   icmp->icmp_seq,
	   ip->ip_ttl, 
	   rtt  
	   );
	     
	}
}
 
void tv_sub(struct timeval *out,struct timeval *in)
{   
	 if((out->tv_usec -= in->tv_usec)<0)
	 {--out->tv_sec;
	  out->tv_usec+=1000000;
	 }
out->tv_sec -= in->tv_sec;

}