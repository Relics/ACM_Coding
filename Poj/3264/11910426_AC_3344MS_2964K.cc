#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int apex=0x7FFFFFFF;
const int fundus=0;
const int maxnum=50010;
int height[maxnum];
int max_ans;
int min_ans;
typedef struct
{
	int l;
	int r;
	int _max;
	int _min;
}Node;

Node segment_tree[3*maxnum];//二叉树的大小为结点个数的三倍

void build_tree(int l,int r,int root)
{
	segment_tree[root].l=l;
	segment_tree[root].r=r;
	if(l==r)
	{
		segment_tree[root]._max=segment_tree[root]._min=height[l];
	}
	else
	{
		int mid=(l+r)>>1;
		build_tree(l,mid,root<<1);
		build_tree(mid+1,r,(root<<1)+1);
		segment_tree[root]._max=max(segment_tree[root<<1]._max,segment_tree[root<<1|1]._max);
		segment_tree[root]._min=min(segment_tree[root<<1]._min,segment_tree[root<<1|1]._min);
		//segment_tree[root]._max=max(segment_tree[2*root]._max,segment_tree[2*root+1]._max);
		//segment_tree[root]._min=min(segment_tree[2*root]._min,segment_tree[2*root+1]._min);
	}
	return;
}

void search_tree(int l,int r,int root,int a,int b)
{
	if(a==l&&b==r)
	{
		if(segment_tree[root]._max>max_ans)
			max_ans=segment_tree[root]._max;
		if(segment_tree[root]._min<min_ans)
			min_ans=segment_tree[root]._min;
	}
	else
	{
		int mid=(l+r)>>1;
		if(mid>=b)
			search_tree(l,mid,root<<1,a,b);
		else if(a>=mid+1)
			search_tree(mid+1,r,(root<<1)+1,a,b);
		else
		{
			search_tree(l,mid,root<<1,a,mid);
			search_tree(mid+1,r,(root<<1)+1,mid+1,b);
		}
	}
	return;
}

int main()
{
	int n,q;
	cin>>n>>q;
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&height[i]);
	build_tree(1,n,1);
	while(q--)
	{
		max_ans=fundus;
		min_ans=apex;
		int a,b;
		scanf("%d%d",&a,&b);
		search_tree(1,n,1,a,b);
		printf("%d\n",max_ans-min_ans);
	}
	system("pause");
	return 0;
}
