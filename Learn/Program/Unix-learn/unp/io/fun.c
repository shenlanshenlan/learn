
//  广播和sendmsg recvmsg
//函数
#include "/home/k/include/fun.c"
 //  服务器程序
void dg_echo(int sockfd,SA * pcliaddr,socklen_t clilen)
{
	int n;
	socklen_t len ;
	char mesg[MAX];

	for( ;  ; )
	{		len = clilen;
		//n = recvfrom(sockfd,mesg,MAX,0,pcliaddr,&len);//返回mesg
        读取消息

		sendto(sockfd,mesg,n,0,pcliaddr,len);//回射 mesg

		}
}

void dg_cli(FILE *fp,int sockfd,   SA*pservaddr,socklen_t
		servlen)
	{   
		int n;
		socklen_t  	len;
		struct 		sockaddr *preply_addr;
		char 		sendline[MAX],recvline[MAX+1];
		struct      msghdr    msg;
		struct      iovec     iovec;
		int         flags;

		preply_addr = malloc(servlen); //申请地址空间长度为servlen
    	char       *addr;
    	int		    on=1;
	   //设置套接字为广播
		setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on)); 
                                      

		while(fgets(sendline,MAX,fp)!=NULL)
	{
    
     //sendto(sockfd,sendline,strlen(sendline),0,pservaddr,servlen);
	 //初始化消息结构
	 iovec.iov_base = sendline;
	 iovec.iov_len = strlen(sendline);
     msg.msg_name = pservaddr;     
     msg.msg_namelen = servlen;
     msg.msg_iov  = &iovec;
	 msg.msg_iovlen      = 1;
     sendmsg(sockfd,&msg,flags);
 
        len = servlen;
		

    n = recvfrom(sockfd,recvline,MAX,0,preply_addr,&len);
 
 
        char   *aa;
	    aa= k_ntop((SA *)preply_addr);
	 	printf("reply from %s (ignored)\n",aa);//打印服务地址
  	
		fputs(recvline,stdout);                //输出消息
  }
}
 