#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxnum=110;

int cards[maxnum];
int dp[maxnum][maxnum];
int come_on_dp(int i,int j)
{
	if(i==j||i==j-1)
		return dp[i][j]=0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i+2==j)
		return dp[i][j]=cards[i+1]*cards[i]*cards[j];
	int k;
	for(k=i+1;k<=j-1;k++)
	{
		if(dp[i][j]==-1)
			dp[i][j]=come_on_dp(i,k)+come_on_dp(k,j)+cards[k]*cards[i]*cards[j];
		else
			dp[i][j]=min(dp[i][j],come_on_dp(i,k)+come_on_dp(k,j)+cards[k]*cards[i]*cards[j]);
	}
	return dp[i][j];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&cards[i]);
	}
	dp[1][N]=come_on_dp(1,N);
	printf("%d\n",dp[1][N]);
	//system("pause");
	return 0;
}