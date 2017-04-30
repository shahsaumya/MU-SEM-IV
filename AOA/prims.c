#include <stdio.h>
#define MAX 10
#define INF 1000
int adj[MAX][MAX];
int minKey(int key[MAX], int mst_set[MAX], int n)
{
	int min = INF, min_index,i;
	for (i = 0; i < n; i++)
	{
		if(mst_set[i]==0 && key[i]<min)
		{
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}
void prims(int adj[MAX][MAX], int n)
{
	int i,u,v;
	int parent[MAX];
	int key[MAX];
	int mst_set[MAX];
	for (i = 0; i < n; ++i)
	{
		key[i]=INF;
		mst_set[i]=0;
	}
	key[0]=0;
	parent[0]=-1;
	for(i=0;i<n;i++)
	{
		u = minKey(key, mst_set, n);
		mst_set[u] = 1;
		for(v=0;v<n;i++)
		{
			if(adj[u][v] && mst_set[v]!=1 && adj[u][v]<key[v])
			{	parent[v]=u;
				key[u] = adj[u][v];
			}
		}
	}
	printf("Edge   Weight\n");
   	for (i = 1; i < n; i++)
      printf("%d - %d    %d \n", parent[i], i, adj[i][parent[i]]);

}
void main()
{
	int i,j,n;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	prims(adj,n);
}