#include<stdio.h>
int result[2];
struct pair
{
	int min,max;
};
struct pair min_max(int a[],int i,int j)
{
	struct pair minmax;
	struct pair mm1,mm2;
	int mid;
	if(i==j)
	{
		minmax.min=minmax.max=a[i];
		return minmax;
	}
	else if(i==j-1)
	{
		if(a[i]>a[j])
		{
			minmax.min = a[j];
			minmax.max = a[i];
		}
		else
		{
			minmax.min = a[i];
			minmax.max = a[j];
		}
		return minmax;
	}
	else
	{
		mid = (i+j)/2;
		mm1 = min_max(a,i,mid);
		mm2 = min_max(a,mid+1,j);
		  /* compare minimums of two parts*/
  		if (mm1.min < mm2.min)
    		minmax.min = mm1.min;
  		else
    		minmax.min = mm2.min;     
 
  /* compare maximums of two parts*/
  		if (mm1.max > mm2.max)
    		minmax.max = mm1.max;
  		else
    		minmax.max = mm2.max;     
  		return minmax;
	}
}
int main()
{
	int n,i;
	int a[10];
	struct pair minmax;
	printf("Enter number of elements in array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	minmax = min_max(a,0,n-1);
	printf("Maximum = %d",minmax.max);
	printf("Minimum = %d",minmax.min);
	return 0;

}