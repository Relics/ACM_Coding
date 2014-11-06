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
const int maxnum=32010;
const int _max=15010;
typedef struct
{
	int l,r;
	int number;
}Node;

Node star[3*maxnum];
int res[_max];
int star_num;
void make_tree(int l,int r,int root)
{
	star[root].l=l;
	star[root].r=r;
	star[root].number=0;
	if(l==r)
		return;
	else
	{
		int mid=(star[root].l+star[root].r)>>1;
		make_tree(l,mid,root<<1);
		make_tree(mid+1,r,root<<1|1);
	}
}
void count_star(int l,int r,int root)
{
	if(star[root].l==l&&star[root].r==r)
	{
		star_num+=star[root].number;
	}
	else 
	{
		int mid=(star[root].l+star[root].r)>>1;
		if(l>mid)
		{
			count_star(l,r,root<<1|1);
		}
		else if(r<=mid)
		{
			count_star(l,r,root<<1);		
		}
		else
		{
			count_star(l,mid,root<<1);
			count_star(mid+1,r,root<<1|1);
		}
	}
	return;
}

void insert_star(int l,int r,int root,int x)
{
	int mid=(star[root].l+star[root].r)>>1;
	if(x>=l&&x<=r)
	{
		star[root].number++;
	}
	if(l==r)
		return;
	if(x<=mid)
	{
		insert_star(l,mid,root<<1,x);
	}
	else
	{
		insert_star(mid+1,r,root<<1|1,x);
	}
}
int main()
{
	make_tree(0,32000,1);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		star_num=0;
		int x,y;
		scanf("%d%d",&x,&y);
		count_star(0,x,1);
		++res[star_num];
		insert_star(0,32000,1,x);
	}
	for(int i=0;i<n;i++)
		printf("%d\n",res[i]);
	//system("pause");
	return 0;
}
