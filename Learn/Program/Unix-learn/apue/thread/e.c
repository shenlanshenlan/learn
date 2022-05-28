//线程与信号
//进程将信号分发到所有的线程，线程屏蔽字则决定是否处理该信号

#include "include.h"
pthread_t   tida,tidb;

 sigset_t           set1;   //信号集

void  f1();
void  f2();
void *tf1();
void *tf2();
void setmask();
void send1();


int main() 
{   
    send();
 
     
    signal(SIGUSR1,f1);                       //设置信号处理程序
    signal(SIGUSR2,f2);                       //设置信号处理程序
    pthread_create(&tida,NULL,tf1,NULL);               //创建线程a
    pthread_create(&tidb,NULL,tf2,NULL);               //创建线程b
    sleep(5);
   send1();
  for( ; ; )
  {}
}


void  f1()
{   
    printf("this is f1\n");
    
}
void  f2()
{
    printf("this is f2\n");
}
void *tf1()  //线程函数1
{   
     printf("this is tf1\n");
    Stime();
   for( ; ; )
{}
}
void *tf2()  //线程函数1
{    
    
    printf("this is tf2\n");
    Stime() ;
    for( ; ; )
    {}
}

 void setmask(){
      
       sigemptyset(&set1);            //初始化
       sigaddset(&set1,SIGUSR2);      //添加阻塞信号sigusr1
	   sigaddset(&set1,SIGUSR1);      //添加阻塞信号sigusr1
       pthread_sigmask(SIG_SETMASK,&set1,NULL); //设置屏蔽字 
	   printf("sig is set,this is tf   \n");
}
 void send1()
 {
      if(pthread_kill(tida,SIGUSR1)!=0) 
      ERR 
      else
      OK 
        if(pthread_kill(tidb,SIGUSR1)!=0) 
      ERR 
      else
      OK 

 }