#include<graphics.h> 
#include<Xlib.h/X11.h>
int main()
{
   XInitThreads();
   int gd = DETECT,gm = VGAMAX,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
   initgraph(&gd,&gm,NULL);
   rectangle(left, top, right, bottom);
   circle(x, y, radius);
   bar(left + 300, top, right + 300, bottom);
   line(left - 10, top + 150, left + 410, top + 150);
   ellipse(x, y + 200, 0, 360, 100, 50);
   outtextxy(left + 100, top + 325, "C Graphics Program");
   delay(10000);
   closegraph();
   return 0;
}
