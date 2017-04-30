#include <stdio.h>
#include <graphics.h>
#include <math.h>
void pixel(int xc, int yc, int x, int y)
{
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	putpixel(xc+y,yc+x,WHITE);
	putpixel(xc+y,yc-x,WHITE);
	putpixel(xc-y,yc+x,WHITE);
	putpixel(xc-y,yc-x,WHITE);
}
int main()
{
	float xinc,yinc,x,y,xc,yc,r,d;
	int i,gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	printf("Enter center and radius\n");
	scanf("%f %f %f",&xc,&yc,&r);
	delay(10000);
	x = 0;
	y = r;
	pixel(xc,yc,x,y);
	d = 1.25 -r;
	while(x<y)
	{
		if(d<0)
		{
			x = x+1;
			d = d+3+2*x;
		}
		else
		{
			x = x+1;
			y = y-1;
			d = d+5+2*(x-y);
		}
		pixel(xc,yc,x,y);
		delay(100);
	}
	delay(30000);
	closegraph();
}