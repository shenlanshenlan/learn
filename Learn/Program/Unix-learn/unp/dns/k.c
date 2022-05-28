//  getaddrinfo  //dns 地址域名转换

//测试 输出  getaddrinfo  结构
#include "include.h"
	struct addrinfo   set,  *kg,  *g_info;

int main(int argc ,char *argv[])
{	   memset(&set,0,sizeof(struct addrinfo));
  	//初始化set info 地址结构
 		set.ai_flags = AI_CANONNAME;
    //设置其返回规范主机名

	if(getaddrinfo(argv[1],argv[2],&set,&g_info)!=0)
	  //获取info 地址结构
	{printf("函数返回错误\n");
		exit(0);
		}  
       //设置

		
		kg=g_info;
 do{	  
	printf("hostname:%s\n",kg->ai_canonname); //输出canonname 名称
	printf("%d\n",kg->ai_family);              //输出协议族
 
    char    add[50];
    struct  sockaddr_in *ad;
  	
		ad=(struct sockaddr_in*)kg->ai_addr;     //转换地址结构IPv4
	  
	  inet_ntop(kg->ai_family,&ad->sin_addr,add,50);//转换IP地址

  	printf("%s\n",add);                          //输出IP地址
   } while((kg=kg->ai_next)!=NULL);           //循环输出结构链表

exit(0);
}
