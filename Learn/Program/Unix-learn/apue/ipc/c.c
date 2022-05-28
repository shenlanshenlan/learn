//  管道  标准IO库 poen
#include "include.h"

FILE  *frite;
FILE  *command;
char  *cmd="/bin/sh";
char   *s;
int main(int argc,char *argv[])
 {	
     
 	  // 	fgets(s,20,stdin);
		//	OK
		//  fputs(s,stdout);
   	//	printf("s\n",s);

    char *a;
    a =argv[1];
		if(argc!=2)
		{ERR
		  exit;
			}
    frite=	popen(cmd,"w");
		     
 	  printf("%s\n",a);	
		fputs(a,frite);
	
	exit(0);
	
	}


	  
