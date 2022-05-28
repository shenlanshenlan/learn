
//复杂 c 表达式

#include "k.h"
int i;
typedef char (*ap)[5];
ap foo(char *p){                 //
 for(i = 0;i<3;i++)
 {  
    p[strlen(p)] = 'A';   //p现在为一个字符串
 }
return (ap)p+1;
}
 
char   (*w[2])() ;

char   (*t)();
 
char   (*(*f())[2])() 
{
    
  return  &w;
}
 
char    *(*(*p)[])  ;
  typedef   int *(*(* ad)[])   ;
int main()
{/*
  char s[] = "FROG\0SEAL\0LION\0LAMP";

   puts(foo(s)[1] +2);
   cout(s);*/
  void * s;
  void *e;
   w[0] = t;         
   s= (char *(*(*)[]))e;
   

return 0 ;
}

/*

     










**/