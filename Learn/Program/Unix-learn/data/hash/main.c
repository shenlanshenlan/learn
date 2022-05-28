//  hash table 

#include "k.h"
#include "hash.c"



int main()
{
 
EL   *b;

     b =init_table();
   printf("%p\n",b+1);       
 
      
     
   insert(8,"mama",b);
  insert(15,"yaoyao",b);
 
EL f;
f = find(8,b); 
 if(f == NULL)
 cout("find NULL");
else
  cout(f->name);
 
cout(b[8]->name);

}





