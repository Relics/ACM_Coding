#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;


//扩展欧几里得定理
long long exdgcd(long long a,long long b,long long &x,long long &y)
{
	long long ans;
	long long temp;
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		ans=exdgcd(b,a%b,x,y);
		temp=x;
		x=y;
		y=temp-a/b*y;
		return ans;
	}
}
int main()
{
	long long x,y,m,n,l;
	while(scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l)!=EOF)
	{
		long long ans;
		long long X,Y;
		long long gcdans=exdgcd(n-m,l,X,Y);
		if((x-y)%gcdans)
			printf("Impossible\n");
		else
		{
			ans=(x-y)/gcdans*X;
			if(ans<0)
			{
				long long counts=abs(ans/l)+1;
				ans=ans+counts*l;
			}
			else
			{
				long long counts=ans/l;
				ans=ans-counts*l;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}