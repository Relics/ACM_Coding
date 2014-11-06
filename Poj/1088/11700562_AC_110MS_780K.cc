#include <iostream>
using namespace std;

int a[110][110];
int dp[110][110];
int row,column;

int max(int i,int j)
{
	return (i>j)?i:j;
}
int maxlength(int i,int j)
{
	int maxlen=1;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i>1&&a[i][j]>a[i-1][j])
	{
		maxlen=maxlength(i-1,j)+1;
	}
	if(i<row&&a[i][j]>a[i+1][j])
	{
		maxlen=max(maxlength(i+1,j)+1,maxlen);
	}
	if(j>1&&a[i][j]>a[i][j-1])
	{
		maxlen=max(maxlength(i,j-1)+1,maxlen);
	}
	if(j<column&&a[i][j]>a[i][j+1])
	{
		maxlen=max(maxlength(i,j+1)+1,maxlen);
	}
	return maxlen;
}

int main()
{
	int i,j;
	int max=0;
	cin>>row>>column;
	for(i=0;i<=row;i++)
	{
		for(j=0;j<=column;j++)
		{
			a[i][j]=0;
			if(i!=0&&j!=0)
				cin>>a[i][j];
			dp[i][j]=-1;
		}
	}
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=column;j++)
		{
			dp[i][j]=maxlength(i,j);
		}
	}
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=column;j++)
		{
			if(max<dp[i][j])
				max=dp[i][j];
		}
	}
	cout<<max<<endl;

	return 0;
}