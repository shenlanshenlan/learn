/*
c++ 中的引用  &

*/


#include <iostream>

using namespace std;


void t(int &b)   //函数中传引用
{
 b =5;
} 
  /*********测试引用虚函数****/
class a{
public:
virtual  void r(){ cout<<"a\n";  }
};

class c :public a{
public:    
    virtual  void r(){ cout<<"c\n";  }
    };
 
int main(){

    int  a1 =10;
    int &b = a1;   //  引用
    cout<<b<<endl;     //  输出10

    t(b);              // 此处 a 和 b  效果一样
    cout<<b<<endl;     //输出  5
    
     c  o1;       //声明一个子类对象
     a   &s = o1; //用父类对象 引用子类对象 
     s.r();       //此处输出 c  调用子类的方法
} 