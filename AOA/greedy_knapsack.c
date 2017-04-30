#include<stdio.h>
struct Details
{
	int wt;
	int profit;
	float ppwt;
}d[10],temp;

int main()
{
	int i,n,wt,p,max_wt,j,tot=0;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter the details\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i].wt);
		scanf("%d",&d[i].profit);
		d[i].ppwt = ((float)d[i].profit)/d[i].wt;
	}
	printf("Enter maximum weight\n");
	scanf("%d",&max_wt);
	for(i=0;i<n-1;i++)
	{
		for (j=0;j<n-1;j++)
		{
			if(d[j].ppwt<d[j+1].ppwt)
			{
				temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;
			}
		}
	}
	for (i = 0; i < n; ++i)
	{
		printf("%d\t%d\t%f\n",d[i].wt,d[i].profit,d[i].ppwt);
	}
	for(i=0;i<n;i++)
	{
		if(max_wt>=d[i].wt)
		{
			max_wt-=d[i].wt;
			tot+=d[i].profit;
		}
		else if(max_wt==0)
			break;
		else
		{
			tot+=(d[i].ppwt*max_wt);
			max_wt = 0;
		}
	}
	printf("Total profit %d\n",tot);
	return 0;
}