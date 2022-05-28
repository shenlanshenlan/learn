/*单例模式
  c++ 中的一个静态成员函数访问这个对象
  唯一的一个实例

*/

#include <iostream>
using namespace std;

class singleton
{
public:   
 static void instance( ){cout<<"this obj\n";}
 
};
 
int main()
{

singleton::instance();


}

