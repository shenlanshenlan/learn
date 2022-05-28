//  获取地址  gethostbyname  

#include "include.h"



int main(int argc, char **argv)
{	  
    struct hostent *hptr;                
		char *  ptr,**pptr;
		char    str[INET_ADDRSTRLEN];

 	 	while(--argc>0){
		ptr = *++argv;   														// 第二个参数
    if((	hptr = gethostbyname(ptr)) == NULL)		  //函数调用
		{		printf("返回为空\n");
		 continue;
		 }
		 printf("hostname   %s\n",hptr->h_name);
			
   for(pptr=hptr->h_aliases;*pptr!=NULL;pptr++)
	   printf("talias    %s\n",*pptr);

		 switch(hptr->h_addrtype)
		 {
				case AF_INET:                          //获取IPv4 地址
				 pptr = hptr->h_addr_list;
			   for( ;*pptr!=NULL;pptr++)
  if(inet_ntop(hptr->h_addrtype,*pptr,str,sizeof(str))==-1) 
					  printf("addr is wrong\n");
				 
				 printf("address:%s\n",str);

						 break;
						 default:
						 
						ERR
						break;
			}
		}

exit(0);

}
