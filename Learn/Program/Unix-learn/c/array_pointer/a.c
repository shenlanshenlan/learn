
//# 二维数组传参数

#include <stdio.h>
#include <string.h>
#include "k.h"

char **p;            //二维指针 指向指针的指针？？
char *ss = "xingke"; //此方式声明的为只读变量
char s2[7] = "xingke";
 
/*//二维数组

void f(char a[][20]) //形参 格式  a[10][20] 或者 a[][20]  前一个数值可省略
{
  int i;
  for (i = 0; i < 2; i++)
  {
    printf("函数内打印二维数组%s\n", a[i]);
  }
  strcpy(a[0], "xingke"); //测试2 函数内改变数组元素1
}
void fun(char **a)
{
  char *p;
  while ((p = *a++) != NULL)
  {
    printf("函数内打印二维指针%s\n", p);
  }
}*/
void fun1( char * p[])
{

  printf("打印 p+1 p:%s\n",*(p+1));  //打印字符串    //
  printf("打印 p[0]:%s\n",p[0]);  //打印字符串    //

  **p = 't';
  printf("打印 p **p = 't':%s\n",p[0]);  //打印字符串    //
  p++;
  printf("打印p:%s\n",*p);  //打印字符串    //
}
int main()
{
  //二维数组
  // f(s);                               //测试1 成功调用f 带入二维数组
  //printf("函数外测试数组%s\n", s[0]); //测试2 该值在函数内被改变

  //二维指针
  char s = 'e'; //声明变量的同时 分配了存储空间;

  //错误操作
  //p[1]="yuxinji";    错误语句 p[1] 仅仅是一个地址 并没有实体存储空间存储字符串
  //二维指针的操作
  //错误操作
  /*char *o; //
   *o =  s;*/

  //*p = &s; 错误语句 对一个指针取值 首先该指针必须先有值
  //正确操作 字符
  /* char *d;            //声明一个指针变量
  printf("地址 %p\r\n", p);
  p = &d;     
  d = NULL ; //给指针一个地址
  printf("地址 %p\r\n", *p);
  d = &s;           //p 存储指针d 的地址
  printf("地址 %p\r\n", *p);
  
  **p = 'g'; //正确执行
  printf("字符%s\n",*p);
 OK 
 char *ff;
    ff = &s;   
                                     //*p = f;                  错误语句  对一个指针取值 首先该指针必须先有值
  printf("地址 %p\r\n", ff);
  printf("字符%s\n",ff); */

  //正确操作 字符串
 /* p = &ss;
  printf("字符串%c\n", **p); //打印一个字符
  printf("字符串%s\n", *p);  //打印字符串

  char *o;
  o = s2;     //一级指针直接用数组名赋值
  p = &o;     //二级指针指向一级指针的地址

  **p = 'k';      //正确操作
  printf("字符串%s\n", *p);  //打印字符串    //
  */
  char  a = 'h';
  char  *c;
  char  b[8] = "yuxinji";
                                                        // char **argc =  char *argc[];
  char  * s4[] = {"xingke","yxinji"}; 
  char  * s5[2];
     c = &a;
     s5[0] = c;
     s5[1] = b; 
     p=&c;
     c =&b[0]; //关键点 重点  p 指向s5是指针 
     c = &b[0];
     fun1(p); 
 
  
   
 

   
}
