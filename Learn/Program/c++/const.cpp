// Console.cpp : 定义控制台应用程序的入口点。
//

#include "head.h"
#include "ui.h"
#include "t1.h"
#include <stdio.h>
#include <iostream>

//const 参数
void fun(const int a) {
	//a = 10;
}
int main() {
	using namespace std;
	const int a = 10;
	int b = 20;
	int x = 30;

	int& y = b;  //引用 只是变量的别名 
	//a = 11; //错误 不可修改

	const int *c = &a;  //不能改变指向的值
	c = &b; //争取 修改其地址
//*c = 12; //错误 不可修改其值
	 int const *d = &a; //写法同上
	 d = &b;
	 //*d = 99;

	 int * const p = &b; //不可修改的指针
	 //p = &x;  指针不可修改

	 y = 9;

	cout << *c<<endl;  //输出9
	cout << *d<<endl; //输出9
	cout << b<<endl; //输出9
    return 0;
}