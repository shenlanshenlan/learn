"udp  调用函数

#include "include.h"

int 
udp_client(const char *host,const *serv,SA **saptr,socklen_t *lenp)
 						//1主机名，服务名，地址结构，长度
{    
 		int sockfd,n;
		struct 	addrinfo	 hints,	*res,	*ressave;
		memset(&hints,sizeof(struct addrinfo));//初始化info结构
 		//此结构用于设置返回地址
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_DGRAM;

		if((n=getaddrinfo(host,serv,&hints,&res))!= 0)
		   { ERR exit(0);} //错误退出程序
		ressave = res;   
		 
		 do{
		   sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);	
			 if(sockfd>=0)
			 break;
			 } while((res =res->ai_next)!=NULL);

			 if(res == NULL)
			    { ERR exit(0);}  //错误返回 无可用地址
	    
			//创建成功以后的执行
			*saptr = malloc(res->ai_addrlen);
			 memcpy(*saptr,res->ai_addr,res->ai_addrlen);
			 *lenp = res->ai_addrlen;												//
			 freeaddrinfo(ressave);         							  //释放info

			 return(sockfd);
	}



