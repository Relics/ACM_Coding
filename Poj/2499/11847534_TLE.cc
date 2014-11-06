#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int i=1,N;
	cin>>N;
	while(N--)
	{
		int l=0,r=0;
		int m,n;
		scanf("%d%d",&m,&n);
		for(;;)
		{
			if(1==m&&1==n)
				break;
			if(m>n)
			{
				m=m-n;
				l++;
			}
			if(m<n)
			{
				n=n-m;
				r++;
			}
		}
		printf("Scenario #%d:\n",i++);
		printf("%d %d\n\n",l,r);
	}
	return 0;
}