#include<stdio.h>
int minimum(int a[10],int j,int n)
{
	int i,min,pos = j;
	min = a[j];
	for(i=j+1;i<n;i++)
	{
		if(a[i]<min)
		{	min = a[i];
			pos = i;
		}
	}
	return pos;
}
void sort(int a[10],int n)
{
	int i,min_pos,temp;
	for(i=0;i<n;i++)
	{
		min_pos = minimum(a,i,n);
		temp = a[i];
		a[i] = a[min_pos];
		a[min_pos] = temp;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int n,i;
	int a[10];
	printf("Enter number of elements in array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,n);
	return 0;

}