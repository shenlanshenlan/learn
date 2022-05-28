
//main test getaddrinfo

#include "fun.c"

int main(int argc ,char * argv[])
{ 
	 int  test;
	 test=tcp_connect(argv[1],argv[2]);
	  
		 if(test<0)
		 return 0;
	}
