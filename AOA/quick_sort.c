#include<stdio.h>
int partition(int a[10],int beg,int end)
{
	int i,pindex,pivot = a[end],temp;
	i=pindex=beg;
	for(i=beg;i<end;i++)
	{
		if(a[i]<pivot)
		{
			temp = a[i];
			a[i] = a[pindex];
			a[pindex] = temp;
			pindex++;
		}
	}
	temp=a[end];
	a[end]=a[pindex];
	a[pindex]=temp;
	return pindex;

}
void quick_sort(int a[10],int beg,int end)
{
	int pos;
	if(beg<end)
	{
		pos = partition(a,beg,end);
		quick_sort(a,beg,pos-1);
		quick_sort(a,pos+1,end);
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
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}