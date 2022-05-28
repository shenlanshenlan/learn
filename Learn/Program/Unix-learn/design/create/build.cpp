/* 生成器模式
  创建行为由 directx 执行
  
  但 directx初始化需要 一个build类的实例对象
  
  build 作为抽象类将被继承创建不同子类  
  该类的实例对象作为 director的构造参数  

  director始终 调用 该实例的 buildpart（）成员函数

*/

#include <iostream>
using namespace std;

class build
{
public:
  virtual void buildpart()=0;
};

class concretebuild:public build
{ 
public:
    void buildpart(){cout<<"this is concretebuild\n";}
    void getresult(){};
};

class director
{
public:
    director(build * a){ 
     
         cout<<"这里获取build的对象实例，初始化 director";  
     };
public:   
  void construct(){ cout<<"this director\n"; } 
};

class client{
public:
    build *p;
    director * p2;
};

int main(){
 client a;
 a.p = new concretebuild;
 a.p2 = new director(a.p);
}