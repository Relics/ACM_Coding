#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int apex=0x7FFFFFFF;
const int fundus=0;
const int maxnum=50000;
int a[maxnum];
int dp[maxnum];
int left_max[maxnum];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		dp[n]=a[n],left_max[n]=a[n];
		for(int i=n-1;i>=1;i--)
		{
			dp[i]=max(dp[i+1]+a[i],a[i]);
			left_max[i]=max(dp[i],left_max[i+1]);
		}
		dp[1]=a[1];//这里也可以求一个right_max[i]，但是仔细想想也不需要了
		for(int i=2;i<=n;i++)
		{
			dp[i]=max(dp[i-1]+a[i],a[i]);
		}
		long long ans=0;
		for(int i=2;i<=n-1;i++)
		{
			if(ans<(long long)(dp[i-1]+a[i+1]))
				ans=(long long)(dp[i-1]+a[i+1]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
