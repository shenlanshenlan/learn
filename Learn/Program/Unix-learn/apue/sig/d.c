
//信号实验   屏蔽字 sigflag//
#include "include.h"

void kk();
void set_us2();      //使用sigaction
void us2();
void tspend();
void one();
void uu();
void us1();

struct sigaction ksig;     //变量声明
 sigset_t     tspending;
 sigset_t           set1,set2;
 sig_atomic_t       flag ;

 
int main()
{    one();  
     pause();
          
		                              //在处理函数外设置屏蔽字
       sigemptyset(&set1);            //初始化
       sigaddset(&set1,SIGUSR2);      //添加阻塞信号sigusr1
	   sigaddset(&set1,SIGUSR1);      //添加阻塞信号sigusr1
	   sigprocmask(SIG_SETMASK,&set1,&set2); //设置屏蔽字 
	   printf("sig is set");

 
         
   while(flag==0)
     sigsuspend(&set2);

  for(  ; ; )    //使程序循环 等待信号
 {           }

}
//2222222222222222222222222222222222222222
void set_us2()    //使用SIGACTION 该函数整合了零碎的操作 直接设置 处理函数 信号集 等
{   
    sigemptyset(&ksig.sa_mask);            //初始化
    sigaddset(&ksig.sa_mask,SIGUSR2);      //设置屏蔽字

    ksig.sa_handler=us2;                   //设置处理程序                
	  ksig.sa_flags =0;
    sigaction(SIGUSR2,&ksig,NULL);
}
void us2()     //处理函数
	{  
	printf("this is us2\n");
 
	sleep(10);
	 tspend();


	}
//2222222222222222222222222222222222222222
	void tspend()                   //获得系统屏蔽字
	{  
	   //sigemptyset(&tspending);
		    if(sigpending(&tspending)<0)       //返回当前屏蔽的集
			   ERR
			   else
			   OK
		if(sigismember(&tspending,SIGUSR2))
		  printf("usr is pending\n");
		else
	  printf("can not get spending  \n ");	
	}
 
//11111111111111111111111111111111111111
void one()
		{ signal(SIGUSR1,us1);           //设置处理函数          
          signal(SIGUSR2,uu);           //设置处理函数     
  
		}
void kk()//在此处理函数中 首先屏蔽了SIGUSR1信号，然后休眠（期间发送的USR2信号被阻塞）
{    printf("this is kk\n");
	
	   sigemptyset(&set1);            //初始化
       sigaddset(&set1,SIGUSR2);      //添加阻塞信号sigusr1
	   sigaddset(&set1,SIGUSR1);      //添加阻塞信号sigusr1
	   sigprocmask(SIG_SETMASK,&set1,NULL); //设置屏蔽字   
	  
	                   
    //	set_alarm(); 不能形成循环
	// 	pause();
        sleep(10);  //睡眠10秒 然后测试其屏蔽字 
	  	tspend();
		printf("结束处理函数");
 
}
void us1(){
 printf("this us 1\n");  
flag=1;
 }

void uu(){
	printf("this uu\n");
}

