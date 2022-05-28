
#include <stdio.h>
//#include <apue.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
//#include <unistd.h>

char path[20];


//char * pach1=&pach;
int  fd; //文件描述符
int  size =30;
char   content[6];
char *name="xingdake";


int

main(int argc,char *argv[])

{
   // read(1,path,20);
   // path[20]='\n';
    fd= open(argv[1],2|O_APPEND);
    printf ("%d\n",fd);
  if(fd>2)
  {   printf("file is opened\n"); 
     read(fd,content,size);
     printf("%s\n",content);
     write(fd,name,9);
}
else
    printf ("%d\n",fd);
		printf ("%s\n",path);	
}
