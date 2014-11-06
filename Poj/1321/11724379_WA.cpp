#include <iostream>
using namespace std;

int count=0;
char chessBoard[9][9];
bool chessBool[9][9];
bool chessColumn[9];
int n,k;
int counted_k=0;

void DFS(int row)
{
	int j;
	if(counted_k==k)
	{
		count++;
		return;
	}
	if(row>n)
		return;
	for(j=1;j<=n;j++)
	{
		if(chessBool[row][j]&&!chessColumn[j])
		{
			chessColumn[j]=true;
			counted_k++;
			DFS(row+1);
			counted_k--;
			chessColumn[j]=false;
		}
		//DFS(row+1);
	}
	DFS(row+1);
}

int main()
{
	int i,j;
	cin>>n>>k;
	while(n!=-1&&k!=-1)
	{
		memset(chessBool,false,sizeof(chessBool));
		memset(chessColumn,false,sizeof(chessColumn));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>chessBoard[i][j];
				if(chessBoard[i][j]=='#')
					chessBool[i][j]=true;
				else
					chessBool[i][j]=false;
			}
		}
		DFS(1);
		cout<<count<<endl;
		cin>>n>>k;
	}

	return 0;
}