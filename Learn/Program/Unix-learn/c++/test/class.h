 
//类
#ifndef _class_h
#define _class_h

#include <iostream>
#include  <string>
using namespace std;


class abstract   //具有纯虚函数的抽象类
{
public:
   int ss ; 
   abstract  *p;
   
   
              abstract() ;
   // virtual  ~abstract() ; //抽象类必须是虚析构函数

    virtual void show(string c) =0;   //纯虚函数
          
};


class a : public abstract    //子类 a
{ 
public: 
     a();
    ~a();

    virtual void show(string c) ;   //纯虚函数
};

 



class b : public a    //子类 b
{ 
public: 
     b();
    ~b();

    virtual void show(string c) ;   //纯虚函数
};

#include "./class.cpp"









#endif