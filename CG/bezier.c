#include<graphics.h>
#include<stdio.h>
#include<math.h>

void main()
{
	int x[4];
	int y[4];
	int gd = DETECT, gm,i;
	float t,px,py;
	initgraph(&gd,&gm,NULL);
	printf("Enter control points\n");
	for(i = 0; i <= 3; i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	for(t = 0; t <= 1; t += 0.001)
	{
		//cleardevice();
		px = pow((1-t),3)*x[0] + 3*pow((1-t),2)*t*x[1] + 3*(1-t)*t*t*x[2] + t*t*t*x[3];
		py = pow((1-t),3)*y[0] + 3*pow((1-t),2)*t*y[1] + 3*(1-t)*t*t*y[2] + t*t*t*y[3];
		putpixel(px,py,GREEN);
		delay(1);
	}
	closegraph();
	return 0;
}