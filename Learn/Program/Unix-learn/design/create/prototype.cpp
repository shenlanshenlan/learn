/* prototype 原型




*/
#include <iostream>
using namespace std;

class graphic{          //绘制
public:
    virtual  void draw( ){cout<<"绘制graphic\n";}; 
    virtual  graphic * clone(){ };
}; 
class music :public graphic 
{ 
public:
    void  draw(){cout<<"绘制music\n";}
    graphic * clone(){ return new music;}
};

class tool      //工具抽象类
{ 
public:
  virtual void manipulate(graphic *p) = 0;
};


class graphictool :public tool        //工具具体类   此类的实例对象 将保存原型
{
public:
      graphictool(music * m)         //构造函数 实例话时需要 一个实例指针
      { 
       _music = m;                    //初始化实例
      }


     graphic  *prototype;              //一个抽象类指针 
    void manipulate(graphic *p)     //此函数需要一个具体的类指针
    {         
        prototype = p->clone();
        prototype->draw(); 
    };


    music * _music;                   //原型
};


int main()
{     
    graphictool  o(new  music);
    o.manipulate(o._music);
}
