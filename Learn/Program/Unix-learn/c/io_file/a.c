#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int fd=0;
int main(int argc,char * argv[])
 {


puts(argv[1]);
// printf("%s,\n",grgv[1]);
fd =  open(argv[1],O_RDONLY);
//printf("%d",argv[1]);

if( fd == -1)
{
printf("error\n");
}
else 
{
printf("ok\n");
} 
return 0; 
 // printf(fopen);
char k[10];

 k = "xingke";




}
