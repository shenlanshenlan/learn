  //  使用 io函数 读取输出图片

#include "k.h"

int main(){
   
 
  int   fd ;
  int    n;
  int   sum ;
  char buf[1000000];

   //标准IO库
  /*file = fopen("/home/k/K/a.jpg","rb");
     fread(buf,1,1000000,file);

  file = fopen("/home/k/K/new.jpg","a+b");
    fwrite(buf,1,1000000,file);*/


  //API
  fd = open("/home/k/K/a.jpg",O_RDONLY);
  sum = 0;
  int i = 0;
    for( ;i<1;i++)
     {
      n = read(fd,buf ,652259);
      printf("%d\n",n);
     } 
  fd = open("/home/k/jpg/xingke.jpg",O_CREAT);
  fd = open("/home/k/jpg/xingke.jpg",O_WRONLY);
     printf("%d\n",fd);
     int ff =  write(fd,buf,n); 
     printf("%d\n",ff);
   
}