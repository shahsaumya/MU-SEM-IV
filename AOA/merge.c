#include<stdio.h>
int temp[10];
void merge(int a[10],int beg,int mid,int end)
{
	int i,j,k=beg,loop;
	i = beg;
	j = mid+1;
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
			temp[k] = a[i];
			i++;
		}
		else
		{
			temp[k] = a[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[k]=a[i];
			k++;
			i++;
		}
	}
	for(loop = beg;loop<k;loop++)
	{
		a[loop] = temp[loop];
	}
}
void merge_sort(int a[10],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid = (beg+end)/2;
		merge_sort(a,beg,mid);
		merge_sort(a,mid+1,end);
		merge(a,beg,mid,end);
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
	merge_sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}