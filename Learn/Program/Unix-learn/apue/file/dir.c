#include "include.h"

char *pathname ="/home/k/learn/apue/file/k";

struct  stat st;



int main()
{
  if(stat(pathname,&st)<0)
    ERR
  if(S_ISREG(st.st_mode))    //测试此文件是不是普通文件件
    OK
  if(access(pathname,R_OK)<0)  //access 测试权限
    ERR
   else 
    OK
char * newpath="/home/k/ss";
 //  if( link(pathname,newpath)<0)//创建文件链接
 //   ERR

}





