#include <stdio.h>
#include <graphics.h>
#include <math.h>
int main()
{
	float xinc,yinc,x,y,x1,y1,x2,y2,l,dx,dy;
	int i,gd = DETECT,gm,a=1;
	initgraph(&gd,&gm,NULL);
	printf("Enter start and end points\n");
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	delay(10000);
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	if(dx>=dy)
	{
		l = dx;
	}
	else
	{
		l = dy;
	}
	xinc = (x2-x1)/l;
	yinc = (y2-y1)/l;
	x=x1;
	y=y1;
	putpixel((int)x,(int)y,WHITE);
	for(i=0;i<l;)
	{
				if(i%10==0)
					a=5;
				else
					a=1;
				x=x+a*xinc;
				y=y+a*yinc;
				putpixel((int)x,(int)y,WHITE);
				delay(100);
				i+=a;

	}
	delay(30000);
	closegraph();
	return 0;
}