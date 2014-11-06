#include <iostream>
#include <algorithm>
using namespace std;

char puzzle[21][21];
int ans[21][21];
int c,r;
int dp(int i,int j)
{
	if(ans[i][j]!=-1)
		return ans[i][j];
	ans[i][j]=1;
	if(i>1)
		if(puzzle[i-1][j]=='.')
		{
			puzzle[i-1][j]='#';
			ans[i][j]+=dp(i-1,j);
		}
	if(i<r)
		if(puzzle[i+1][j]=='.')
		{
			puzzle[i+1][j]='#';
			ans[i][j]+=dp(i+1,j);
		}
	if(j>1)
		if(puzzle[i][j-1]=='.')
		{
			puzzle[i][j-1]='#';
			ans[i][j]+=dp(i,j-1);
		}
	if(j<c)
		if(puzzle[i][j+1]=='.')
		{
			puzzle[i][j+1]='#';
			ans[i][j]+=dp(i,j+1);
		}
	return ans[i][j];
}
int main()
{
	for(;;)
	{
		int i,j;
		cin>>c>>r;
		if(c==0&&r==0)
			break;
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				cin>>puzzle[i][j];
		memset(ans,-1,sizeof(ans));
		int dpmax=-1;
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=r;j++)
			{
				if(puzzle[i][j]=='@')
					break;
			}
			if(puzzle[i][j]=='@')
				break;
		}
		dpmax=dp(i,j);
		cout<<dpmax<<endl;
	}
	return 0;
}