
#include "k.h"

void fun(int *a){
 
 a[1] = 5;

}

int 
main ()
{
    int b[2] ={1,2};
    fun(b);
    
    printf("%d",b[1]);
}