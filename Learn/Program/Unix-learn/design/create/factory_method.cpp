/*  工厂方法
   
   





*/
#include <iostream>
using namespace std;
 

class product
{
};

class concrete:public product
{
};

class creator
{
public:
  virtual product * factorymethod() = 0;
  void anoperation(){};
};

class concretecreator:public creator
{
public:
  virtual product * factorymethod(){ cout<<"here return a object to creator\n";
                                     return new concrete;}
  //在这个子类中 创建需要的相关对象
};

class client
{
public:   
    product  *p;   //此指针将指想一个 具体的产品
    creator  *p2;  //此指针将指向 一个 具体的创建者对象 ;
};

int main(){
 client a;
  concretecreator  o;    //一个 具体的创建者对象

  a.p2 = &o;
 
  a.p = a.p2->factorymethod();             //获得一个具体产品
 
}
