#include "include.h"
#include <signal.h>

void sig_usr() ;

int main()
	{
  if(signal(SIGUSR1,sig_usr)==SIG_ERR)
    ERR;
  if(signal(SIGUSR2,sig_usr)==SIG_ERR)
     ERR; 
	for( ; ; )
 pause();

}  

 void sig_usr(int signo)
{   if(signo=SIGUSR1)
  	  printf("received SIG1\n");
    else	if (signo=SIGUSR2)
						 printf("received SIG2\n");
          else  ERR
}
