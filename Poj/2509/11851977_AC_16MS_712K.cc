#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)==2)
	{
		int maxcounts=n;
		int butts=n;
		for(;;)
		{
			if(butts<k)
				break;
			maxcounts+=butts/k;
			butts=butts%k+butts/k;
		}
		printf("%d\n",maxcounts);
	}
	return 0;
}