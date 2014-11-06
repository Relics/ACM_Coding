#include <stdio.h>

int main()
{
	int N,Q;
	int cow[50001];
	int group[200001];
	int a;
	int b;
	int big=0;
	int small=1000000;
	int i,j;
	scanf("%d%d",&N,&Q);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&cow[i]);
	}
	for(i=1;i<=Q;i++)
	{
		scanf("%d%d",&a,&b);
		for(j=a;j<=b;j++)
		{
			if(cow[j]>big)
				big=cow[j];
			if(cow[j]<small)
				small=cow[j];
		}
		printf("%d\n",big-small);
		small=1000000;
		big=0;
	}

	return 0;
}





