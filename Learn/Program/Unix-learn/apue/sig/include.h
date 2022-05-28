#include <stdio.h>        //输入输出
#include <sys/wait.h>     //进程等待
#include <stdlib.h>       //
#include <sys/stat.h>     //文件结构stat
#include <unistd.h>       //文件权限access
#include <setjmp.h>   	  //跳转
#include <time.h> 		  //时间



#define ERR printf("error\n");
#define OK  printf("ok\n");
#define S1  printf("this s1\n");
#define S2  printf("this s2\n");

 
