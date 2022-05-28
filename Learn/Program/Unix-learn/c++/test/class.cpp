
#ifndef _class_cpp
#define _class_cpp
//类

#include <iostream>
#include  <string>
#include  "./class.h"
using namespace std;

 
abstract::abstract(){
 cout<<"this is abstract create\n";
}/*
abstract::~abstract(){
 
 delete    p;   
 cout<<"this is abstract delete\n";
} */
 void abstract:: show(string c){
 
} 

 



 a::a(){
     cout<<"this is a create\n"; 
     ss = 5;
 }
 a::~a(){
     cout<<"this is a delete\n";
 }
 void a::show(string c)
 { 
   cout<<c;
 }



b::b(){
    cout<<"this is b create\n"; 
    ss = 5;
}
b::~b(){
    cout<<"this is b delete\n";
}
void b::show(string c)
{ 
  cout<<c;
}


 #endif