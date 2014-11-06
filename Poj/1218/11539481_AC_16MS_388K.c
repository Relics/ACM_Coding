#include <stdio.h>

int main()
{
	int N,i,j;
	int n;
	int answer[101]={0,1,1,1,2,2};
	int cout;
	for(i=6;i<101;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(i%j==0)
				cout++;
		}
		if(cout%2==1)
			answer[i]=answer[i-1]+1;
		if(cout%2==0)
			answer[i]=answer[i-1];
		cout=0;
	}
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&n);
		printf("%d\n",answer[n]);
	}
	return 0;
}