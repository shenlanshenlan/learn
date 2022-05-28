
/*
client: 抽象类指针   ------->该抽象类拥有多个子类以拥有多个不同的创建工厂
          |
          v
        创建具体工厂对象->该对象 创建具体组件
               
  客户拥有抽象类指针或具体对象

 重点在于 用创建工厂类（该类被继承，拥有不同子类，此类被复用，该抽象类作为统一接口）  的实例对象  创建组件

 在运行时刻创建一个concretefactory类的实例 此（具体）类 创建 特定：的（创建工厂）对象
 该工厂对象   创建指定产品组件


*/
#include <iostream>
using namespace std;
 
class ab_factory                        //抽象接口
{ 
public:
   virtual void createproductA()=0;       //虚函数1
   virtual void createproductB()=0;       //虚函数2
};
 
class concretefactory1:public ab_factory     //具体类1
{
public:
    virtual void createproductA(){};       //虚函数1
    virtual void createproductB(){};       //虚函数2 
};
class concretefactory2:public ab_factory      //具体类2
{
public:
    virtual void createproductA(){cout<<"congcrete a\n";}        //虚函数1
    virtual void createproductB(){cout<<"congcrete b\n";}        //虚函数2 
};


class client
{  
public:
     ab_factory   *p;         //拥有抽象类指针
   

};

int main() {
  
    client a;
 
    a.p = new concretefactory2;
    a.p->createproductB();


}



