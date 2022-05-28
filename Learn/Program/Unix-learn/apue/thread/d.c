//屏障

#include "include.h"
int  x=0; 
int  p=0;
pthread_t  s1,s2,s3;    //线程ID
pthread_mutex_t    mutex = PTHREAD_MUTEX_INITIALIZER ;   //互斥
pthread_barrier_t  bar ;
void *fun(){
 
pthread_mutex_lock(&mutex);     //锁定 
printf("this is thread:%d\n",(unsigned long)pthread_self());
int  v=200;
p+=1;
int  i=0;
for(i;i<v;i++)
    {
        x+=1;
    } 

     printf("this is %d\n",p);
pthread_mutex_unlock(&mutex);  //解锁
 pthread_barrier_wait(&bar);      
  //下面是屏蔽到达以后的事情
 sleep(2); 
 
}



int main()
{ 
    if(pthread_barrier_init(&bar,NULL,3)<0)  //初始化屏障
    ERR

         if(pthread_create(&s1,NULL,fun,NULL)<0)
    ERR   
         if(pthread_create(&s2,NULL,fun,NULL)<0)
    ERR
         if(pthread_create(&s3,NULL,fun,NULL)<0)
    ERR



sleep(8);
    printf("%d\n",x);

}