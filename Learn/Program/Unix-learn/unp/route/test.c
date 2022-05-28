//路由套接字
//#include "k.h"
#include "/home/k/include/include.h"
#include <net/route.h>
//#include <net/if_dl.h>
#define BUFFLEN  (sizeof(struct rt_msghdr)+512)

#define SEQ 9999

int 
main(int argv,char *argc[])
{
 //分配变量
	int							 sockfd;    
    struct           rt_msghdr  *rtm;
	char             *buf;
	pid_t  						pid;
	ssize_t  				n;
	struct re_msghdr   *rtm;
	struct sockaddr  *sa,*rti_info[RTAX_MAX];
	struct sockaddr_in  *sin;

	if(argc != 2)
	  {
			printf("参数错误\n");
			exit(0);
			}

		
//  创建套接字
	sockfd = socket(AF_ROUTE,SOCK_RAW,0);
//  初始化消息机构
   buf = calloc(1,BUFLEN);  //申请缓冲区
   
	 rtm = (struct rt_msghdr*)buf; 

	 rtm->rtm_msglen = sizeof(struct rt_msghdr)+sizeof(struct sockaddr_in);
	 rtm->rtm_version = RTM_VERSION;
	 rtm->rtm_type = RTM_GET;
	 rtm->rtm_addrs = RTA_DST;
	 rtm->rtm_pid = pid = getpid();
	 rtm->rtm_seq = SEQ;
	 
	 sin = (struct sockaddr_in *)(rtm +1);//rtm剩下的空间转换为套接字地址空间
   

	 //初始化套接字地址结构
	 sin ->sin_len = sizeof(struct sockaddr_in);
	 sin->sin_family = AF_INET;
	 inet_pton(AF_INET,argv[1],&sin->sin_addr);
	  
 //写入套接字
	 write(sockfd,rtm,trm->rtm_msglen);

	 do{
	 n = read(sockfd,rtm,BUFLEN);
	   
	}while(rtm->rtm_type != RTM_GET||rtm->rtm_SEQ !=SWQ||rtm->rtm_pid != pid);

	//~~~~~~~~~~~~~~~~~~~~~
	  rtm = (struct rt_msghdr *)buf;
		sa  = (struct sockaddr *)(rtm+1);
		get_rtaddrs(rtm->rtm_addrs,sa,rti_info);
		if((sa = rti_info[RTAX_DST])!=NULL)
	        printf("dest:%s\n",sock_ntop_host(sa->sa_len));

		if((sa = rti_info[RTAX_NETMASK]) != NULL)
  		printf("netmask:%s\n",sock_masktop(sa, sa->sa_len));

		if((sa = rti_info[RTAX_GENMASK]) != NULL)
				printf("genmask:%s\n",sock_masktop(sa,sa->sa_len));

				exit(0);
	}














