#include<stdio.h>
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int i,j,n=8,l;
	int score1, score2;
	int temp[8];
	printf("Number of players is 8\n");
	for(i=n;i>1;i=i/2)
	{
		int k=0;
		for(j=0;j<n;j+=2)
		{
			printf("Match between %d and %d\n",a[j],a[j+1]);
			printf("Enter scores of both\n");
			scanf("%d %d",&score1,&score2);
			if(score1>score2)
			{
				printf("The winner is %d\n",a[j]);
				temp[k] = a[j];
				temp[k+(n/2)] = a[j+1];
			}		
			else
			{
				printf("The winner is %d\n",a[j+1]);
				temp[k] = a[j+1];
				temp[k+(n/2)] = a[j];
			}			
			k++;
		}
		for(l=0;l<n;l++)
		{
			a[l] = temp[l];
		}
		n=n/2;
	}
	printf("The winner is %d\n",a[0]);
	return 0;
}