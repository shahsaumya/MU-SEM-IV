#include <stdio.h>
#include <graphics.h>
#include <math.h>
int main()
{
	float xinc,yinc,x,y,x1,y1,x2,y2,l,dx,dy,e;
	int i,gd = DETECT,gm,a=1;
	initgraph(&gd,&gm,NULL);
	printf("Enter start and end points\n");
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	delay(10000);
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	if(x1<x2)
	{
		xinc = 1;
	}
	else
	{
		xinc = -1;
	}
	if(y1<y2)
	{
		yinc = 1;
	}
	else
	{
		yinc = -1;
	}
	x = x1;
	y = y1;
	putpixel((int)x,(int)y,WHITE);
	if(dx>=dy)   //slope < 1
	{
		e = 2*dy-dx;
		i=0;
		while(i<=dx)
		{
			if(i%10==0)
				a=5;
			else
				a=1;
			if(e<0)
			{
				e=e+2*dy;
				x=x+1*a;
			}
			else
			{
				e=e+(2*dy-2*dx);
				x=x+1*a;
				y=y+1*a;
			}
			putpixel((int)x,(int)y,WHITE);
			delay(100);
			i+=a;
		}
	}
	else   //slope < 1
	{
		e = 2*dx-dy;
		i=0;
		while(i<=dy)
		{
			if(i%10==0)
				a=5;
			else
				a=1;
			if(e<0)
			{
				e=e+2*dx;
				x=x+1*a;
			}
			else
			{
				e=e+(2*dx-2*dy);
				x=x+1*a;
				y=y+1*a;
			}
			putpixel((int)x,(int)y,WHITE);
			delay(100);
			i+=a;
		}
	}
	delay(30000);
	closegraph();
	return 0;
}
