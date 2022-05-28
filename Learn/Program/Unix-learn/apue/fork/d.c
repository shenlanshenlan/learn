#include "include.h"

static void chatout(char *);

int main()
{
pid_t pid;
 if ((pid = fork())<0)
{ printf("error");
}else if (pid == 0)
{   chatout("output from child\n");
}else{
  	chatout("output from parent\n");
} 
  exit(0);
}
static void
chatout (char *str)
{  char *ptr;
	 int   c;
 setbuf(stdout,NULL);
  for(ptr=str;(c=*ptr++)!=0;)
    putc(c,stdout);
}
