#include <stdio.h>

int main()
{
	int N;
	int k;
	int i,j;
	int maxunhappy;
	int maxunhappyday;
	scanf("%d",&N);
	while(N!=0)
	{
		maxunhappy=8;
		maxunhappyday=0;
		for(k=1;k<=N;k++)
		{
			scanf("%d%d",&i,&j);		
			if(i+j>maxunhappy)
			{
				maxunhappy=i+j;
				maxunhappyday=k;
			}
		}
		if(maxunhappyday!=0)
			printf("%d\n",maxunhappyday);
		else
			printf("0\n");
		scanf("%d",&N);	
	}
	return 0;
}
