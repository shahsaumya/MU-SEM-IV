#include<stdio.h>
int rec_bin(int a[],int low,int high,int x)
{
	int mid;
	if(low==high)
	{
		if(a[low]==x)
		{
			return low;
		}
		else
		{
			return 0;
		}
	}

	else
	{
			mid = (low+high)/2;
			if(a[mid]==x)
			{
				return mid;
			}
			else if(x<a[mid])
			{
				return rec_bin(a,low,mid,x);
			}
			else
			{
				return rec_bin(a,mid+1,high,x);
			}
	}
}
int main()
{
	int n,i,x,result;
	int a[10];
	printf("Enter number of elements in array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter search number\n");
	scanf("%d",&x);
	result = rec_bin(a,0,n-1,x);
	if(result==0)
	{
		printf("Number not found\n");
	}
	else
	{
		printf("Number found at %d\n", (result+1));
	}
	return 0;
}