//创建型模式 最初示例代码 
//  创建迷宫

//#include "k.h"


#include  <iostream>
#include  <string>

using namespace std;

typedef int direction; 
static int roomno=0;
#define north 2 
#define east  3 
#define south 4
#define west  1 

class mapsite
{  
public:
	virtual void enter()=0;
    virtual char show(int s)=0;
};

 
class room : public mapsite{
public: 
    room(){		
		this->_roomnumber = roomno;
		roomno++;
	  }
    mapsite * getside(direction) const{}
	
	virtual void enter(){} 
  
  void     setside(direction S,mapsite *b){
 
		   switch(S)
		 { 
			 case  1 :
			 { 
				  this->_sides[0] = b;  
				  break;
			 }
			 case 2:
			 { 
				  this->_sides[1] = b;  
				  break;
			 }	
			 case 3:
			 { 
				  this->_sides[2] = b;  
				  break;
			 }		
			 case 4:
			 { 
				  this->_sides[3] = b;  
				  break;
			 }		 
 
		 }
	 }
  virtual  char show(int s){	
	  
	 char a =	this->_sides[0]->show(1); 
	 char b =   this->_sides[1]->show(2); 
	 char c = 	this->_sides[2]->show(3); 
	 char d = 	this->_sides[3]->show(4);  
	
	cout 
	  <<"   "<<b<<b<<b<<b   <<endl
	  <<"  |    |    "<<endl
	  <<"  " <<   a<<"    "<< c     <<endl
      <<"  |"<<d<<d<<d<<d<<"|"<<endl;

	return 'a';
	  }
 
private:
 		 mapsite * _sides[4];
		 int _roomnumber;
}; 

class wall :public mapsite{
public:
 	     wall(){}
		 virtual void enter(){}
		 virtual char show(int s){
			switch(s)
			{ 
				case 1: 
				   return '|';
				   break;
				case 2:
		  
				return  '-';
				break;
	  
				case 3: 
				 return '|';
				break;
				 case 4:
			  
				 return '-';
				break;
			 
			}
		 }
};
class door:public mapsite{
public:
	door(room*  a,room*   b){
	   this->_room1 = a;
	   this->_room2 = b;
	   this->_isopen = false;
	}
	virtual char show(int s){
	   switch(s)
	   { 
		   case 1: 
			  return '<';
			  break;
		   case 2:
	 
		   return '^';
		   break;
 
		   case 3: 
		   return '>';
		   break;
    		case 4:
		 
		    return 'v';
		   break;
		
	   }
	 }
	virtual void enter(){}
	room * othersidefrom(room*);
private:
	room * _room1;
	room * _room2;
	bool   _isopen;
};
class maze{
public :
   maze(){
	  this->empty = 0;  
   }
   virtual void show(){
    for(int i=0;i<this->empty;i++){
      this->display(rm[i]);
	}
}
void display(room *x){
	  x->show(1); 
	  
}
   

 void addroom(room  *x ){
       rm[empty]=x;
       empty++;
  }
  room * roomno(int x) const{

     return this->rm[x];//返回x房间
  }
 
private:
    room *rm[10];
	int   empty; 
	//存储迷宫地图
};

class mazegame{
 public: maze * createmaze();
 
};



int main()
{   
	maze  *m;
 	mazegame a;
    m = a.createmaze();
    m->show();

}


maze *mazegame::createmaze(){
	 maze * amaze = new maze;
	 room * r1  =   new room;
	 room * r2  =   new room;
	 door * thedoor = new door(r1,r2);
	 
	 amaze ->addroom(r1);
	 amaze ->addroom(r2); 
     
	r1-> setside(north, new wall);
	r1-> setside(east , thedoor);
	r1-> setside(south, new wall);
	r1-> setside(west , new wall);

	r2-> setside(north,new wall);
	r2-> setside(east,new wall);
	r2-> setside(south,new wall);
	r2-> setside(west,thedoor);


  return amaze;
}








