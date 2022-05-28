
#ifndef  tree_h
#define  tree_h

#include "k.h"

#define M   4 
#define LEAF   1 
#define NODE   0 
typedef struct treenode * node;
typedef struct treenode * leaf;



struct  treenode{
      
      node p[M ];
      int  key[M ]; 
      char *name[M];
      int num;
      int type;       //node type
};

  
node makeempty(node r);  // 创建一个内部节点和一个叶节点
node insert(int x,node r,char *name);

leaf insert_leafnode(int x, leaf r,char *name);
// 添加到叶子节点中
leaf init_leaf(leaf t);
//初始化叶节点
#include "tree.c" 

#endif