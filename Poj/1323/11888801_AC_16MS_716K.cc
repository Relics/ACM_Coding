#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int card[1001];

int main()
{
	int casenum=1;
	for(;;)
	{
		memset(card,0,sizeof(card));
		int m,n;
		scanf("%d%d",&m,&n);
		if(m==0&&n==0)
			break;
		int has_used=0;
		int has_bigger=0;
		int winner_round=0;
		for(int i=1;i<=n;i++)
		{
			int temp;
			scanf("%d",&temp);
			card[temp]=1;
		}
		for(int i=m*n;i>0&&has_used<n;i--)
		{
			if(has_bigger>(n-has_used))
				break;
			if(card[i]&&has_bigger==0)
			{
				winner_round++;
				has_used++;
			}
			else if(card[i]&&has_bigger)
			{
				has_bigger--;
				has_used++;
			}
			else if(!card[i])
			{
				has_bigger++;
			}
		}
		printf("Case %d: ",casenum++);
		printf("%d\n",winner_round);
	}
	return 0;
}