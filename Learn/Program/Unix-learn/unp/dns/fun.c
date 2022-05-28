//    getaddrinfo 
//通过主机名称获取其地址

#include "include.h"

int
tcp_connect(const char *host,const char *serv)
{
 	int sockfd, n;
	struct addrinfo hints,*res,*ressave;

	memset(&hints,0,sizeof(struct addrinfo));	    //初始化
	hints.ai_family =	AF_UNSPEC;								  //地址??? 协议族 指定主机和服务  适用的任何地址和协议
	hints.ai_socktype = SOCK_STREAM;    				  //套接字类型
	//hints 其他成员并未初始化 无需填写？？



	if((n=getaddrinfo(host,serv,&hints,&res))!=0) 
		{	printf("getaddrinfo erro ");
			exit(0);
	 	}
			ressave = res;  //res 为返回的info结构   保存其指针以便释放内存空间
	do{
	  sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);  //直接使用返回结构创建套接字
		// 创建套接字1协议族2套接字类型3长度


		if(sockfd<0)
		 continue;    //如果创建失败，进入下一循环
		if(connect(sockfd,res->ai_addr,res->ai_addrlen)==0) //创建套接字如成功返回套接字
			break;
			close(sockfd);
		}while((res=res->ai_next)!=NULL);
		if(res == NULL)
		   printf("tcp_connect error for %s,%s",host,serv);
			 freeaddrinfo(ressave);     												//释放内存空间
			 return(sockfd);                                    //返回创建的套接字  
	}
	/////////////////////tcp_listen///////////////

	int
	tcp_listen(const char *host,const char *serv,socklen_t *addrlenp)
{   
    int listenfd,n;
		const int on = 1;
		struct addrinfo hints,*res,*ressave ;//info结构变量
		char   k_addr[100];

		memset(&hints,0,sizeof(struct addrinfo));
		hints.ai_flags = AI_PASSIVE;   //??
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;

		if((n = getaddrinfo(host,serv,&hints,&res))!=0)
				ERR
			ressave = res;              //存著info 结构
			do{  
			   struct sockaddr_in *aa;
			  aa = (struct sockaddr_in*)res->ai_addr;
				 inet_ntop(res->ai_family,&aa->sin_addr,k_addr,100);
				 printf("%s\n",k_addr);         	    
		    //输出IP地址
				  
			   listenfd=
					socket(res->ai_family,res->ai_socktype,res->ai_protocol);
					//创建套接字，1地址结构2套接字类型，长度
				if(listenfd<0)
				continue;
				setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
				if(bind(listenfd,res->ai_addr,res->ai_addrlen)== 0)
				break;

				close(listenfd);
				}while((res = res->ai_next)!=NULL);
		if(res == NULL)
		   ERR

			 listen(listenfd,30);
			 if(addrlenp)
			 *addrlenp = res->ai_addrlen;
			 freeaddrinfo(ressave);
			 return(listenfd);
		}


















