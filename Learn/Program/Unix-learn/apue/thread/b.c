//线程互斥量，时间等待锁定

#include "include.h"

static int test=0;
struct timespec tout;
struct tm       *tmp;
char          buf[64];
int           err;

pthread_t  s1,s2;    //线程ID
pthread_mutex_t    mutex = PTHREAD_MUTEX_INITIALIZER ;   //互斥

void prtime()
{    clock_gettime(CLOCK_REALTIME,&tout);
     tmp=localtime(&tout.tv_sec);
     strftime(buf,sizeof(buf),"%r",tmp);
     printf("get time at:%s\n",buf);
}
void *add()
{    pthread_mutex_lock(&mutex);     //锁定 
        int i;
        int t=10000;
        for(i = 0;i<t;i++)
        { test+=1;}
      
        printf("this is thread:  %d\n" ,(long)pthread_self());
     pthread_mutex_unlock(&mutex);  //解锁
}

int main()
{   
    if(pthread_create(&s1,NULL,add,NULL)<0)
    ERR
    if(pthread_create(&s2,NULL,add,NULL)<0)
    ERR
    pthread_mutex_lock(&mutex);     //锁定 
    prtime();
    tout.tv_sec+=10;
    err=pthread_mutex_timedlock(&mutex,&tout);
    prtime();
    if(err==0)
    OK 
    else
    ERR 
 
 sleep(1);
printf("%d\n",test);

}