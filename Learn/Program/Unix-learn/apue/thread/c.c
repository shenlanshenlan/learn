//条件变量

 


//线程互斥量，时间等待锁定

#include "include.h"
 
int val =0;
pthread_t  s1,s2;    //线程ID
pthread_mutex_t    mutex = PTHREAD_MUTEX_INITIALIZER ;   //互斥

pthread_cond_t      cond = PTHREAD_COND_INITIALIZER;     //条件变量

void *a1();    //生产者
void *a2();    //消费者
 
int main()
{   val=1;              //由a1 将其变为0
    printf("this is main: %d\n",val);
    if(pthread_create(&s1,NULL,a1,NULL)<0)
    ERR
    if(pthread_create(&s2,NULL,a2,NULL)<0)
    ERR
 
 sleep(5);
printf("this is end %d\n",val);

}
void *a1()
{
      pthread_mutex_lock(&mutex);     //锁定 
      val-=1;
      sleep(3);
      OK
      pthread_cond_signal(&cond);
      printf("this is a1 signal sendding: %d\n",val);
     pthread_mutex_unlock(&mutex);  //解锁
}
void *a2()
{    pthread_mutex_lock(&mutex);     //锁定
    if(val != 0) 
     pthread_cond_wait(&cond,&mutex);
 

      printf(" this  is a2 %d\n",val);
     pthread_mutex_unlock(&mutex);  //解锁
}