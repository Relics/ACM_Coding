#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int s,d;
		scanf("%d%d",&s,&d);
		int a=s+d;
		int b=s-d;
		if((a&1)||(b&1)||(d>s))
		{
			printf("impossible\n");
		}
		else
		{
			a/=2;
			b/=2;
			printf("%d %d\n",a,b);
		}
	}
	return 0;
}