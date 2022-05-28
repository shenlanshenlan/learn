  
char  *s1="xinkge";   //全局变量
char  s3[]="xingke";
int   t = 10;
void fun(int a )
{  int  x;
    for( ; ; ) 
    { 
       x= x+a;
       if(x>10)
       break;
    }
}

int main()
{  char h[]= "xingke";  //数组名
   char *u;             //指针
    
   u = h;              //指针赋值

   int a;             //局部变量
   int *p;
   a=5;
   p=&a; //指针赋值

    int  b;
    b=2;
    a=b;  //数值赋值

    char o;  //读取全局变量
    o=s3[2];
    fun(a);
    
    t= 12;   //全局变量赋值

} 
