//标准IO

#include "/home/k/include/include.h"

int main()
{
char buf [100];
int  n;
int  a;

/*
printf("API/IO:\n");
n=read(0,buf,100);
write(2,buf,n);

printf("C/IO\n");
//每只只能输入一个字符
  

a= fgetc(stdin);
   fputc(a,stdout);
printf("一次一行\n");
   char str[100];


  fgets(str,100,stdin);
	 
	 fputs(str,stdout); */
printf("回射");
for (  ;  ; ){
 n=read(0,buf,100);
 write(2,buf,n);
}





}
