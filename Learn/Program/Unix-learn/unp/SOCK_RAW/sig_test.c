
//此程序用于测试 信号如何中断 阻塞

#include "k.h"
#include "/home/k/include/fun.c"
 void sig_alrm()
{
    printf("信号处理程序\n");
    return; 
}



int main() 
{
  signal(SIGALRM,sig_alrm);
 
  char buf[20]; 
  
  alarm(3);    
 
  for( ; ; ){
     cout("1");  
    read(0,buf,20);
     cout("2");
  }


}

