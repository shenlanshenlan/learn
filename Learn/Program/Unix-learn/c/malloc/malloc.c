// malloc 和free 函数

#include "k.h"

int main(){
   char   *p;
	 char 	*s;
    int   *t,*r;
	 
s =	malloc(10);

 // if(p==NULL)
// ERR
    p=s;     // 问题一 s 和  p 指向同样的地址

	*s='x';
	*++s='i';    //问题二 运算顺序问题  s先赋值然后++？？？
  *++s='n';
  *++s='\n';
                     //赋值t  int 
	  t=(int*)s+1;
   	 *t=128;
		r=(t+4);
		*r =55;
     
 

		printf("%sw\n",s-3);  //???
		printf("%d\n",*t);
	  printf("%d\n",*r);
    OK
   	write(1,p ,10);
return (0);
}
