#include <algorithm>
#include <cstdio>
using namespace std;
int a[1050];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		while(k--)
			next_permutation(a,a+n);
		for(int i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
	}
	return 0;
}