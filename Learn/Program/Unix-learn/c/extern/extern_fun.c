 
 #include "extern_fun.h"
int add(int a)
{ 
    extern  int b;   //该变量声明在其他文件中作为全局变量
    //        int b;   //该变量是一个重新声明的局部变量
    a = a+b;
  return a;
}
