#include<stdio.h>
#include<graphics.h>
#include<math.h>
int fact(int n)
{
	if(n==1 || n==0)
		return 1;
	return n*fact(n-1);
}
int bezier(int n, int i)
{
	int res=fact(n)/(fact(n-i)*fact(i));
	return res;
}
void bez();
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	bez();
	bez();
	bez();
	closegraph();
}
void bez()
{
	int n,i;
	double px[10],py[10],u,x,y;

	printf("enter number of points:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter data:");
		scanf("%lf %lf",&px[i],&py[i]);
		putpixel((int)px[i],(int)py[i],YELLOW);
	}
	for(u=0.0;u<1.0;u+=0.0001)
	{
		for(i=0;i<n;i++)
		{
			x+=pow(1-u,n-i-1)*pow(u,i)*px[i]*bezier(n-1,i);
			y+=pow(1-u,n-i-1)*pow(u,i)*py[i]*bezier(n-1,i);
		}
		putpixel((int)x,(int)y,WHITE);
		x=y=0;
	}
}
