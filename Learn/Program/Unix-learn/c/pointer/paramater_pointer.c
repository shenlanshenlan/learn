// 关于指针传值

#include "k.h"
void s1(int *n);
void s2(int *n);
void s3(int *n);

int main()
{
  int a = 1;
  int b = 2;
  int *c;

  s1(&a); 
  printf("%d\n", a);

  s2(&b);          
  printf("%d\n", b);
}

void s1(int *a1)    //正确    把地址传入参数
{
  *a1 = 5;
}

void s2(int *a1)    //错误  函数的形参指针 实际上只是复制该参数
                    //的拷贝 ， 可以改变该指针指向的数据 
                    //但是唯独不能改变该指针本身，因为和实参已经没有
                    //关系，只不过指向的地址相同
{
  int *s;
  s = malloc(4);
  *s = 8;
  a1 = s;
}
