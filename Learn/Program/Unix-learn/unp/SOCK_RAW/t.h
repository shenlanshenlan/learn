// 头文件
#ifndef __T_H
#define __T_H   
 
#define BUFSIZE  1500 
 
#include "k.h"
#include "/home/k/include/fun.c" //公共函数
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
//宏定义
//结构体
struct rec{
u_short rec_seq;
u_short rec_ttl;
struct timeval rec_tv;
};


////////////////////变量声明
struct  addrinfo *ai;
struct  rec      *rec;
int     sockraw,sockudp ; //2个套接字描述符号
struct  sockaddr    
*sasend,*sarecv,*salast,*sabind; //4个地址结构    

struct timeval tvrecv;


pid_t   pid;
u_short sport,dport;
socklen_t salen;
int     gotalarm;
int     max_ttl = 30 ;
int     ttl;
int     seq,code,done;
char    sendbuf[BUFSIZE];
char    recvbuf[BUFSIZE];
int     probe;
int     nprobes;
double  rtt;
/////////////////////函数声明
void sig_alrm(int signo);

int recv_v4(int seq,struct timeval *tval);

int 
sock_cmp_addr(const struct sockaddr *sa1, const struct sockaddr *sa2,
    socklen_t salen);

void tv_sub(struct timeval *out,struct timeval *in);









#endif
