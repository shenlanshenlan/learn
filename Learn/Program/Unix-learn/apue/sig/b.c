#include "include.h"
#include <signal.h>
#include <setjmp.h>

void  display();
static jmp_buf env_alrm;
void sleep1();
int main()
{
setjmp(env_alrm);

OK
 // longjmp(env_alrm,1);
sleep1();
ERR

}


void display()
{  OK
 	 longjmp(env_alrm,1);
   ERR
}
	void sleep1()
{  
  signal(SIGALRM,display);
 // OK	setjmp(env_alrm); 
  alarm(5);
  pause();
  
}	
