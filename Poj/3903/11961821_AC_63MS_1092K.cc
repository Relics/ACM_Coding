#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxnum=100010;
int queue[maxnum];

int binarysearch(int t,int l,int r)
{	
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(queue[mid]<t) l=mid+1;
		else r=mid;
	}
	return l;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int len=0,temp;
		memset(queue,0,sizeof(queue));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			if(temp>queue[len]) queue[++len]=temp;
			else queue[binarysearch(temp,1,len)]=temp;  
		}
		printf("%d\n",len);
	}
	return 0;
}