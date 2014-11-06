#include <iostream>
#include <algorithm>
#include <cstdio>
#define maxnum 10010
using namespace std;

int cycle_length[maxnum];

int main()
{
	int i,j;
	int counts;
	for(i=1;i<=10000;i++)
	{
		counts=1;
		j=i;
		for(;;)
		{	
			if(j==1)
			{
				cycle_length[i]=counts;
				break;
			}
			if((j&1)==1)
			{
				j=3*j+1;
				counts++;
			}
			if((j&1)==0)
			{
				j/=2;
				counts++;
			}
		}
	}
	while(scanf("%d%d",&i,&j)==2)
	{
		int k;
		bool flag=false;
		if(i>j)
		{
			int temp;
			temp=i;
			i=j;
			j=temp;
			flag=true;
		}
		int maxium=cycle_length[i];
		for(k=i;k<=j;k++)
		{
			maxium=max(maxium,cycle_length[k]);
		}
		if(!flag)
			printf("%d %d %d\n",i,j,maxium);
		else
			printf("%d %d %d\n",j,i,maxium);
	}
	return 0;
}