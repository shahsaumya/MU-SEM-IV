#include<graphics.h>>
#include<stdio.h>
void main()
{
	int x,y,tx,ty,xmid,ymid,i,j,xmax,ymax,angle=10;
	int gd=DETECT,gm;
	float b[3][3],p1[] = {50,50,100,50,100,100,50,100,50,50};
	int pi;
	int res[3][3];
	initgraph(&gd,&gm,NULL);
	xmax = getmaxx();
	ymax = getmaxy();
	xmid = xmax/2;
	ymid = ymax/2;
	line(xmid,0,xmid,ymax);
	for(i=0;i<8;i+=2)
	{
		line(xmid+p1[i],ymid-p1[i+1],xmid+p1[i+2],ymid-p1[i+3]);
	}
	line(0,ymid,xmax,ymid);
	printf("Enter arbitrary coordinates\n");
	scanf("%d %d",&x,&y);
	tx=x;
	ty=y;
	b[0][0]=cos(angle*3.14/180);
	b[0][1]=sin(angle*3.14/180);
	b[0][2]=0;
	b[1][0]=-sin(angle*3.14/180);
	b[1][1]=cos(angle*3.14/180);
	b[1][2]=0;
	b[2][0]=-tx*cos(angle*3.14/180)+ty*sin(angle*3.14/180)+tx;
	b[2][1]=-tx*sin(angle*3.14/180)+ty*cos(angle*3.14/180)+ty;
	b[2][2]=1;
	for(i=0;i<9;i+=2)
	{
		a[0][0]=p1[0];
		a[0][1]=p1[1];
		c[0][0]=(a[0][0]*b[0][0])+(a[0][1]*b[1][0])+(a[0][2]*b[2][0]);
		c[0][1]=(a[1][0]*b[0][1])+(a[0][1]*b[1][1])+(a[0][2]*b[2][1]);
		pi[i]=c[0][0];
		pi[i+1]=c[0][1];
	}
	for(i=0;i<8;i+=2)
	{
		line(xmid+pi[i],ymid-pi[i+1],xmid+pi[i+2],ymid-pi[i+3]);
	}
	closegraph();
}
