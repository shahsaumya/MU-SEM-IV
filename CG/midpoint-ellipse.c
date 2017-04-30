#include <stdio.h>
#include <graphics.h>
#include <math.h>
int main()
{
	float xinc,yinc,x,y,xc,yc,r,d,a,b;
	int i,gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	printf("Enter center and values of a and b\n");
	scanf("%f %f %f %f",&xc,&yc,&a,&b);
	x = 0;
	y = b;
	putpixel(x+xc,y+yc,WHITE);
	putpixel(x+xc,yc-y,WHITE);
	putpixel(xc-x,y+yc,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	d = (b*b)+((a*a)*b)+((a*a)/4);
	while((2*b*b*x)<(2*a*a*y))
	{
		if(d<0)
		{
			x = x+1.0;
			d = d+(2*(b*b)*(x))+(b*b);
		}
		else
		{
			x = x+1.0;
			y = y-1.0;
			d = d+(2*(b*b)*(x))+(b*b)-(2*(a*a)*y);
		}
putpixel(x+xc,y+yc,WHITE);
	putpixel(x+xc,yc-y,WHITE);
	putpixel(xc-x,y+yc,WHITE);
	putpixel(xc-x,yc-y,WHITE);
		delay(50);
	}
	d = ((b*b)*(x+0.5)*(x+0.5))+((a*a)*(y-1)*(y-1))-((a*a)*(b*b));
	while(y!=0)
	{
		if(d<0)
		{
			y = y-1.0;
			d = d+(2*(a*a)*y)+(a*a);
		}
		else
		{
			x = x+1.0;
			y = y-1.0;
			d = d+(2*(b*b)*x)+(a*a)-2*(a*a*y);
		}
putpixel(x+xc,y+yc,WHITE);
	putpixel(x+xc,yc-y,WHITE);
	putpixel(xc-x,y+yc,WHITE);
	putpixel(xc-x,yc-y,WHITE);
		delay(50);
	}
	delay(30000);
	closegraph();
	restorecrtmode();
}