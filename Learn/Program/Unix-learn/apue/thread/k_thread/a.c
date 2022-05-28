//  线程函数测试

#include "k.h"

pthread_t ntid;
char *arg = "传入参数，邢柯";
void *re;
void *fun2(void *arg)
{
    printf("this is new thread:\n");
    arg = "线程返回值\n";

    for ( ; ; )
    {
        //pthread_testcancel();  
    }

    return arg;
}

int main()
{

    if ((pthread_create(&ntid, NULL, fun2, arg)) < 0)
        cout("线程创建失败\n");
    sleep(1);
    pthread_cancel(ntid);        
    OK;

    pthread_join(ntid, &re);
    cout(re);
    exit(0);
}