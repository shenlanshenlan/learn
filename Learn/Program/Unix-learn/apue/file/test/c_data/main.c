
// 将C数据结构 存入到硬盘

#include "k.h"
typedef  struct treenode node;
typedef  int    seek;
struct treenode
{    
     node *leftchild;
     seek left;
     node *rightchild;
     seek right;
     char  name[10];  
     
};
int  _seek;
int   file;
int main()
{   
    int size  ;
    size = sizeof(struct treenode);
    node   root,left,right;
    strcpy(root.name,"mama");
    strcpy(left.name,"xingke");
    strcpy(right.name,"yaoyao");

    root.leftchild = &left;
    root.rightchild = &right;
    left.leftchild = NULL;
    left.rightchild =NULL;
    right.leftchild =NULL;
    right.rightchild = NULL;
    
     file = open("./save.txt",O_RDWR);
     /*写入时处理指针关系*/
     root.left = size*1;
     root.right = size*2;    
     write(file,&root,sizeof(root));
     write(file,&left,sizeof(root));
     write(file,&right,sizeof(root));
     close(file);


     file = open("./save.txt",O_RDWR);
     lseek(file,size*2,SEEK_SET);  //文件偏移量记录位置
    
     char buf[size];
     read(file,buf,size);
     node *s ;
     s = (node *)buf;
     cout(s->name);
     close(file);
   

}