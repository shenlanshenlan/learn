/* 结构型模式 
多重继承  匹配 接口不兼容的类

对象组合

*/


#include <iostream>
using namespace std;

    class shape
{
public:
    virtual void draw(){ cout<<"drawing\n";}  
};

    class line :public shape
{ 
public:
    virtual void draw(){ cout<<"画一根 线条\n";}
};

class  text
{ 
public:

     virtual void show() =0;
};
class  word:public text
{
public:
 	virtual void  show(){cout <<"输出一个单词\n";}
}; 
/*********多重继承方式********************/
class adapter : public shape ,public text   //多重继承  用有此两类的 方法   此类作为 一个 适配器
{
public:

    virtual void  draw(){ cout<<"drawing\n";    }  
    virtual void  show(){ cout<<"调用draw\n";    draw()  ;}
}; 

class c: public adapter                     //此类继承自 适配器  有用text的数据  调用 shape的方法
{

};

/*********对象组合方式********************/
class ada:public shape{      //此类包含一个text类的引用  请求时调用 引用实例的方法
public:
      text *p;

  virtual void draw(){
    p = new word;
    cout<<"调用 text 成员 函数\n"; 
    p->show();
  }
};




int main()
{
  line a;
  word b;
	a.draw();
    b.show();
   adapter k;
    
   c e;
   e.show();

   ada j;
   j.draw();


}


 




