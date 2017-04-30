#include<stdio.h>
#include<stdlib.h>
int i,j,n,ne=1,a,b,u,v;
int min,mincost,parent[9],cost[9][9];
int find(int);
int uni(int,int);
void main()
{
	printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					a=u=i;
					b=v=j;
					min = cost[i][j];
				}

			}
		}
		u = find(u);
		v = find(v);
		if(union(u,v))
		{
			min_cost += min;
			printf("%d edge %d-%d = %d\n",ne++;a,b,min);
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
}
int find(int i);
{
	while(parent[i])
	{
		i = parent[i];
	}
	return i;
}
int union(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}