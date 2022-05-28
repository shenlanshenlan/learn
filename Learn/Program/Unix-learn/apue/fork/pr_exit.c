#include "pr_exit.h"
#include <sys/wait.h>
#include <stdio.h>
void 
pr_exit(int status)
{
	if(WIFEXITED(status))
		printf("正常终止  status=%d\n",WEXITSTATUS(status));
 else if(WIFSIGNALED(status))
 			printf("异常终止 signal number = %d%s\n",
			WTERMSIG(status),
#ifdef WCOREDUMP
        WCOREDUMP(status) ? "(产生文件 core file generated)":"");
#else 
       "");
#endif
			else if(WIFSTOPPED(status))
  		printf("暂停child stcpped,signal number = %d\n",WSTOPSIG(status));
}
