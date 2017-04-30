
#include<stdio.h>
#include<math.h>
int board[16];
int place(int row,int column)
{
	int i;
	for(i=0;i<=row-1;i++)
	{
		if(board[i]==column || (abs(board[i]-column)==abs(row-i)))
			return 0;
	}
	return 1;
}
void Queens(int row,int n)
{
	int column,j,l;
	for(column=1;column<=n;column++)
	{
		if(place(row,column))
		{
			board[row]=column;
			if(row==n)
			{
				for(j=1;j<=n;j++)
				{
							printf("\n");						
							for (l=0; l<=n;l++)
						{
							if(board[j]==l)
								printf("\tQ");
							else
								printf("\t-");
						}
				}
			}
			else
				Queens(row+1,n);
		}
	}
}
int main()
{
	int no;
	scanf("%d",&no);
	Queens(1,no);
	return 0;
}