

#include "k.h"

int main(int argc,char **argv )
{     

    int i = 0;
    for(  ;i<argc;i++)
     {    printf("argv%d:%s\n",i,argv[i]);
     }
    int n; 
    char *p ;
    while( (n =  getopt(argc,argv,"nl:"))!= -1)
     {

         
        switch( n){
    case  'n':
        printf("this n\n");
        break;
    case  '?':
        printf("未识别的选项\n");
        break;
    case 'l':
       p = optarg;
       printf("%s\n",p); 
       break; 
        }
     
    }
    printf("optind:%d\n",optind);
    printf("argc  :%d\n",argc );
    printf("~~~~~~~~\nargv char is :%s\n", argv[optind]  );

}