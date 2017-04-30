#include<stdio.h>
int cost[10][10];
void djikstra(int cost[10][10],int startnode,int n)
{
	int distance[9],pred[9];
	int visited[9],count,mindistance,nextnode,i,j;
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=0;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindistance = 999;
		for(i=0;i<n;i++)
		{
			if(distance[i]<mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}
		}
		visited[nextnode]=1;
		for(i=0;i<n;i++)
		{	
			if(distance[i]>mindistance+cost[nextnode][i])
			{
				distance[i]=mindistance+cost[nextnode][i];
				pred[i]=nextnode;
			}
		}
		count++;
	}
}
int main()
{
	int n,i,j,startnode;
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
	printf("Enter starting node\n");
	scanf("%d",&startnode);
	djikstra(cost,startnode,n);
	return 0;
}