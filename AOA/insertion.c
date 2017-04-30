#include<stdio.h>
void sort(int a[10],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		j=i-1;
		temp = a[i];
		while(temp<a[j] && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1] = temp;
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