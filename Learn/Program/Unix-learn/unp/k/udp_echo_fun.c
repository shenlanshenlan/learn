

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
		n = recvfrom(sockfd,mesg,MAX,0,pcliaddr,&len);//返回mesg


		sendto(sockfd,mesg,n,0,pcliaddr,len);//回射 mesg

		}
}

void dg_cli(FILE *fp,int sockfd, const SA*pservaddr,socklen_t
		servlen)
	{
		int n;
		socklen_t  len;
		struct sockaddr *preply_addr;
		char 		sendline[MAX],recvline[MAX+1];
		preply_addr = malloc(servlen); //申请地址空间长度为servlen
    char       *addr;
    int					on=1;
		setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on)); //设置套接字为广播
                                      

		while(fgets(sendline,MAX,fp)!=NULL)
	{
		

		sendto(sockfd,sendline,strlen(sendline),0,pservaddr,servlen);
    len = servlen;
		    n = recvfrom(sockfd,recvline,MAX,0,preply_addr,&len);
		//存储返回的地址			和长度

	 // if(len != servlen || memcmp(pservaddr,preply_addr,len)!=0)
  // {  
        char   *aa;
	      aa= k_ntop((SA *)preply_addr);
  // 	 OK;
	 	printf("reply from %s (ignored)\n",aa);
  //  continue;
// }  
		
		recvline[n] =0;
		fputs(recvline,stdout);
  }
}
