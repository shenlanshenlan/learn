#ifndef  tree_c
#define  tree_c

 
#include "tree.h"


node makeempty(node r)
{  
    node  y ; //创建 根和叶子节点


    if(r == NULL)  //空节点
    {
       r = malloc(sizeof(struct treenode)); 
      
    
    int i ; for( i=0;i<4;i++)
     {     
           r->key[i]=-1;
           r->p[i] = NULL;     
      }  
      r->num =0;
      r->type =NODE;

      return r;
    }
    else 
    return r;
}

node insert(int x,node r,char* name)
{
      if(r ==NULL)  // IF this leafnode is NULL
      {   
          r = init_leaf(r);;
          insert_leafnode(x,r,name);
      }
      if(r->type == LEAF)
      {  
         //  if(r->num ==M) //leaf is full    
  
          
           if(r->num <M) 
          {
          return  insert_leafnode(x,r,name); //save in;
          }
      }
 
    

       if(r->type ==LEAF) // if this node is leaf
       {
              
 


       } 
 
     if(x<r->key[0])  //1
    {
        r->p[0]  = insert(x,r->p[0],name);        
    }

     if(x > r->key[0]  &&  x<r->key[1]) //2
    { 
        insert(x,r->p[1],name);   
    }

     if (x > r -> key[2] && x <r->key[3])   //3
    {
        insert(x,r->p[2],name);    
    }
    if (x > r -> key[3])   //4
    {
        insert(x,r->p[3],name);    
    }



}

leaf insert_leafnode(int x, leaf r,char *name) 
{   
    int i , s;
    for(i = 0; i<r->num ; i++)
    {  

        if( r->key[i] < x  )    
           continue;
         else     // find 
         {                
            for(s = r->num-1;  ;s--)
            {                   
                 r->key[s+1] =r->key[s]; 
                 strcpy(r->name[s+1],r->name[s]);   
                 if(s == i)
                 break;      
            }
 
         }  
     break;       
    }
    r->key[i] = x;
    r->name[i] = name;

 return r;
}

leaf init_leaf(leaf t)
{  
      t = malloc(sizeof(struct treenode));
      int i;
      for(i =0 ; i<M-1;i++)
      {  
        t->key[i] = -1;    
        t->name[i]  =NULL;              
      }
    
    t->num = 0;
    t->type = LEAF;
return t;
}
#endif