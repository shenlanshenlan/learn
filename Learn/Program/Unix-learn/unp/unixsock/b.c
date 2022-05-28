//unix域  客户程序

#include "/home/k/include/include.h"
#define  UNIXSTR_PATH "/tmp/unix.str"


int main(int argv , char argc[])
{	
	char  str[100],ss[100];
	int sockfd;
	struct sockaddr_un servaddr;
  int n,t;
	sockfd = socket(AF_LOCAL,SOCK_STREAM,0);
  
	servaddr.sun_family = AF_LOCAL;
 strcpy(servaddr.sun_path,UNIXSTR_PATH);
	
	connect(sockfd,(SA *)&servaddr,sizeof(servaddr));
  for(  ;  ; )
{
   
	 n=read(0,str,100);

	 write(sockfd,str,n);
	   

   n= read(sockfd,ss,100);
	
	write(1,ss,n);
	

}	
}
