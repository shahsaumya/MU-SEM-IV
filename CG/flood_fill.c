#include <stdio.h>
#include <graphics.h>
#include <math.h>
void ffill(int x, int y,int ocolor,int ncolor)
{
		if(getpixel(x,y)==ocolor)
		{
			putpixel(x,y,ncolor);
			ffill(x+1,y,ocolor,ncolor);
			ffill(x-1,y,ocolor,ncolor);
			ffill(x,y+1,ocolor,ncolor);
			ffill(x,y-1,ocolor,ncolor);
			ffill(x+1,y+1,ocolor,ncolor);
			ffill(x-1,y+1,ocolor,ncolor);
			ffill(x+1,y-1,ocolor,ncolor);
			ffill(x-1,y-1,ocolor,ncolor);
		}
}
int main()
{
	int x,y,ocolor,ncolor;
	int i,gd = DETECT,gm;
	int a[10]={100,100,50,200,100,150,150,200,100,100};
	initgraph(&gd,&gm,NULL);
	printf("Enter fill color\n");
	scanf("%d",&ncolor);
	setcolor(ncolor);
	x = 100;
	y = 125;
	drawpoly(5,a);
	ocolor = getpixel(x,y);
	ffill(x,y,ocolor,ncolor);
	delay(30000);
	closegraph();
	return 0;
}