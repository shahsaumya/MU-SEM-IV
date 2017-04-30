#include<stdio.h>
#include<graphics.h>
#include<math.h>
void multiply(float a[100][3],float b[3][3],float res[100][3],int n);
void main()
{
	float a[100][3],r[3][3],s[3][3],t[3][3],tx,ty,sx,sy,tet;float res[100][3];	int i,x0,y0,j,n,ch,gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	line(320,0,320,700);
	line(0,250,600,250);
	x0=320;y0=250;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			r[i][j]=0;
			s[i][j]=0;
			t[i][j]=0;
		}
	}
	printf("Enter number of vertices of polygon:");
	scanf("%d",&n);
	a[0][0]=a[0][1]=0;
	a[0][2]=1;
	for(i=1;i<n;i++)
	{
		printf("Enter points:");
		scanf("%f",&a[i][0]);
		scanf("%f",&a[i][1]);
		a[i][2]=1;
		line(x0+a[i-1][0],-a[i-1][1]+y0,x0+a[i][0],y0-a[i][1]);
	}
	line(x0+a[i-1][0],-a[i-1][1]+y0,x0+a[0][0],y0-a[0][1]);
	printf("1)Translate\n2)Rotation\n3)Scaling\n4)Exit\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("Enter translation in x and y:");
			scanf("%f %f",&tx,&ty);
			t[0][0]=1;
			t[1][1]=1;
			t[2][0]=tx;
			t[2][1]=ty;
			t[2][2]=1;
			multiply(a,t,res,n);
			for(i=0;i<n-1;i++)
			{
				line(x0+res[i][0],-res[i][1]+y0,x0+res[i+1][0],y0-res[i+1][1]);
			}
			line(x0+res[i][0],-res[i][1]+y0,x0+res[0][0],y0-res[0][1]);
		       break;
		case 2: printf("Enter angle of rotation:");
			scanf("%f",&tet);
			tet=tet*3.14/180;
			r[0][0]=cos(tet);
			r[0][1]=sin(tet);
			r[1][0]=-sin(tet);
			r[1][1]=cos(tet);
			r[2][2]=1;
			multiply(a,r,res,n);
			for(i=0;i<n-1;i++)
			{
				line(x0+res[i][0],-res[i][1]+y0,x0+res[i+1][0],y0-res[i+1][1]);
			}
			line(x0+res[i][0],-res[i][1]+y0,x0+res[0][0],y0-res[0][1]);
		       break;
		case 3: printf("Enter scaling in x and y:");
			scanf("%f %f",&sx,&sy);
			s[0][0]=sx;
			s[1][1]=sy;
			s[2][2]=1;
			multiply(a,s,res,n);
			for(i=0;i<n-1;i++)
			{
				line(x0+res[i][0],-res[i][1]+y0,x0+res[i+1][0],y0-res[i+1][1]);
			}
			line(x0+res[i][0],-res[i][1]+y0,x0+res[0][0],y0-res[0][1]);
			break;
		case 4:break;
	}
	getch();
	closegraph();
}
void multiply(float a[100][3],float b[3][3],float res[100][3],int n)
{
	int i,j,k;
	 for(i=0;i<n;i++)
	 {
		for(j=0;j<3;j++)
		{
			res[i][j]=0;
			for(k=0;k<3;k++)
			{
				res[i][j]+=a[i][k]*b[k][j];
			}
		}
	 }
}