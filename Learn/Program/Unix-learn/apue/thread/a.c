//线程的创建，结束，以及传递参数，获取返回参数
#include "include.h"
#include <pthread.h>
pthread_t ntid; //线程数据结构;
char *arg = "这里是线程参数a";
char *returnarg = "这里是返回参数";
void *re; //返回指针

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid,
		   (unsigned long)tid, (unsigned long)tid);
}
void *thr_fn(void *arg) //新线程执行函数
{
	printf("this is new thread:\n");
	printf("%s", arg);		 //打印参数
	pthread_exit(returnarg); //返回指针
}
void stop1()
{
	printf("this is stop thread :%d", (long)ntid);
	if (pthread_cancel(ntid) < 0) //结束一个进程
		ERR else OK
}

int main()
{
	if (pthread_create(&ntid, NULL, thr_fn, arg) < 0) //线程创建，并传递一个参数
		ERR
			signal(SIGUSR1, stop1);
	//设置一个信号,当信号来临终止一个线程

	printf("this is main thread:\n");
	sleep(5);
	pthread_join(ntid, &re); //获取返回参数
	printf("%s", re);		 //打印返回参数
	pause();
}
