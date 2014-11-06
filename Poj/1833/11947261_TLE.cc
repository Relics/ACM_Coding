#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[1050];

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		for(;;)
		{
			if(k==0)
				break;
			int i,j;
			for(i=n;i>=2;i--)
			{
				if(a[i-1]<a[i])
					break;
			}
			if(i!=1)
			{
				i=i-1;
				for(j=n;j>i;j--)
				{
					if(a[j]>a[i])
						break;
				}
				swap(a[i],a[j]);
				sort(a+i+1,a+n+1);
				k--;
			}
			else
			{
				for(int i=1;i<=n;i++)
					a[i]=i;
				k--;
			}
		}
		for(int i=1;i<=n-1;++i)
			printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	return 0;
}