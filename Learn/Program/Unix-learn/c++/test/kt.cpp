

#include <iostream>
 
using namespace std; 
  
class a                                                         //对象实例 内存中只包含了数据元素，和一个虚表指针，不包含普通函数   
{ 
public:
    int x;
    int y;
    int *p;
    a(){ cout<<"there is class a init"<<endl;}
    virtual ~a(){cout<<"there are delete of a\n";}
     
    //virtual void vir() =0;                                        //如函数中含有纯虚函数则此类为抽象类，其不能创建实例对象
                                                                  //如果继承它的子类没有实现纯虚函数 则该子类仍为抽象类
   
    virtual  void f1(){ cout<<"f1 function"<<endl; };             //虚函数会导致创建 虚表 指针
    virtual  void f2(){ cout<<"f2 function"<<endl;  };    
   
    void f5(){}; 

};

class b:public a                                               //继承类a  将包含类a元素
{ 
public:
      b(){ z=10;};
      void f2(){ cout<<"class b :f2"<<endl;} 
      int  z;
      void f3(){};
};

  void u(){}
 
int main()    //是虚函数时则根据指针初始化的类型   不是虚函数 则根据指针指向对象的初始化类型
{    
     int *p;
     p= new int ; 
     *p = 8;
    
    
    /*//
     b  i;
 
     typedef void (*fun)();
      fun  f;
     
    cout<<"虚表地址"<<(int*)&i <<endl;
    cout<<"虚表函数地址"<<*(int*)(&i) <<endl;
        
 
   // cout<<sizeof(class a)<<endl;
   */
}
