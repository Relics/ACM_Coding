#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int i=1;
		int l=0,r=0;
		int m,n;
		scanf("%d%d",&m,&n);
		for(;;)
		{
			if(1==m&&1==n)
				break;
			if(1==m)
			{
				r+=n-m;
				n=1;
			}
			if(1==n)
			{
				l+=m-n;
				m=1;
			}
			if(m>n)
			{
				l+=m/n;
				m=m%n;
			}
			if(m<n)
			{
				r+=n/m;
				n=n%m;
			}
		}
		printf("Scenario #%d:\n",i++);
		printf("%d %d\n\n",l,r);
	}
	return 0;
}