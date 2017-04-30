#include <stdio.h>
#include <graphics.h>
#include <math.h>
void bfill(int x, int y,int bcolor,int fcolor)
{
		if(getpixel(x,y)!=bcolor && getpixel(x,y)!=fcolor)
		{
			putpixel(x,y,fcolor);
			bfill(x+1,y,bcolor,fcolor);
			bfill(x-1,y,bcolor,fcolor);
			bfill(x,y+1,bcolor,fcolor);
			bfill(x,y-1,bcolor,fcolor);
			bfill(x+1,y+1,bcolor,fcolor);
			bfill(x-1,y+1,bcolor,fcolor);
			bfill(x+1,y-1,bcolor,fcolor);
			bfill(x-1,y-1,bcolor,fcolor);
		}
}
int main()
{
	int x,y,bcolor,fcolor;
	int i,gd = DETECT,gm;
	int a[10]={100,100,50,200,100,150,150,200,100,100};
	initgraph(&gd,&gm,NULL);
	printf("Enter boundary and fill color\n");
	scanf("%d %d",&bcolor,&fcolor);
	setcolor(bcolor);
	x = 100;
	y = 125;
	drawpoly(5,a);
	bfill(x,y,bcolor,fcolor);
	delay(30000);
	closegraph();
	return 0;
}

