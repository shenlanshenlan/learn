

#include "k.h"
 
#include "tree.h"
//未完成    B 树

int 
main()
{

   node  R;
   R = NULL;
   R = makeempty(R);

  /* leaf t;
   t->key[0] =2 ;
   t->name[0] ="yu1" ;


   t->key[1] =5 ;
   t->name[1] ="yu2" ;

   t->key[2] =7 ;
   t->name[2] ="yu3" ;
   
   t->num = 3;
   printf("%s",t->name[2]);
   printf("%s",t->name[3]);
   printf("%d",t->key[3]);*/

    insert_leafnode(6,R,"xingke");

  node k ;
  k = R->p[0];
  printf("%s\n",k->name[0]);

}

