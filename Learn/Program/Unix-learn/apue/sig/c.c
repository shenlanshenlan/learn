//进程屏蔽字 进程跳转  10-20

#include "include.h"

static void 			sig_usr1();
static void    		sig_alrm();
       void   		pr_mask();
static jmp_buf 		jmpbuf;
static volatile   canjmp;


int main()
{ 
	if(signal(SIGUSR1,sig_usr1)==SIG_ERR)
   	ERR
	if(signal(SIGALRM,sig_alrm)==SIG_ERR)
		ERR
	
	pr_mask("starting main:");

	if(sigsetjmp(jmpbuf,1))
	{
	 pr_mask("ending mian:");
	 exit(0);
	}
	canjmp=1;
	for( ; ; )
					pause;
}
void	sig_usr1(int signo)
{
        time_t	starttime;
			if(canjmp == 0)
			return;
pr_mask("startig sig_url"); 

alarm(3);
starttime = time(NULL);
 for( ; ; )
	{			 if(time(NULL)>starttime+5);
	break;
	}
	pr_mask("finishing sig_usr1:");
  canjmp = 0;
	siglongjmp(jmpbuf,1);
}
static void sig_alrm(int signo)
{ 
				pr_mask("in sig_alm:");

}

	void pr_mask()
	{
       ;  }

			

	


