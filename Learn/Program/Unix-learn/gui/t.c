
/*
* Simple Xlib application drawing a box in a window. 
*/  
  
#include <X11/Xlib.h>  
#include <stdio.h>  
#include <stdlib.h>  
  
int main()  
{  
        struct _XDisplay *d;  
        int s;  
        Window w;  
        XEvent e;  
  
        /* To open a connection to the X server that controls a display*/  
        d = XOpenDisplay(NULL);  
        if(d == NULL)  
        {  
                printf("Cannot open display\n");  
                exit(1);  
        }  
  
/* Both return the default screen number referenced by the XOpenDisplay() function */  
        s = DefaultScreen(d);  
  
        /* create window */  
        w = XCreateSimpleWindow(d,  
                                RootWindow(d, s),  
                                50,    //初始位置
                                50,  
                                500,   //窗口大小
                                500,  
                                1,  
                                BlackPixel(d, s),  
                                WhitePixel(d, s));  
  
        /* select kind of events we are interested in */  
        XSelectInput(d, w, ExposureMask | KeyPressMask);  
  
        /* map (show) the window */  
        XMapWindow(d, w);  
  
        /* event loop */  
        while(1)  
        {  
                XNextEvent(d, &e);  
                /* draw or redraw the window */  
                if(e.type == Expose)  
                {  
                        XFillRectangle(d, w, DefaultGC(d, s), 20, 20, 110, 30); 
                        XFillRectangle(d, w, DefaultGC(d, s), 30, 30, 30, 30);
                        XFillRectangle(d, w, DefaultGC(d, s), 40, 40, 30, 30); 
                }  
                /* exit on key press */  
                if(e.type == KeyPress)  
                        break;  
        }  
  
        /* close connection to server */  
        XCloseDisplay(d);  
  
        return 0;  
} 
