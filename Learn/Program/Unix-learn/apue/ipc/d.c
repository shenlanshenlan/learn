// FIFO   命名管道

#include "include.h"

#define  SIZE   10
char *t = "hello world";
int  fd ; 
#define  PATH  "/home/k/learn/apue/ipc/fifo"

int main ()
{   // if( mkfifo(PATH,O_CREAT)<0)
   // ERR
		
  if((fd =open(PATH,O_WRONLY))<0)
 			 S1
  if( write(fd,t,SIZE)<0)
		   S2
		




	exit(0);
	}
