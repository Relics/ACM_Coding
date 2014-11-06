#include <cstdio>
#include <algorithm>
using namespace std;
const int maxnum=100100;
typedef struct
{
	int l,r,color;
	bool lazy;
}tree;
tree color_tree[3*maxnum];

void make_tree(int l,int r,int root)
{
	color_tree[root].color=1;
	color_tree[root].lazy=true;
	if(l==r) return;
	int mid=(l+r)>>1;
	make_tree(l,mid,root<<1);
	make_tree(mid+1,r,root<<1|1);
}
void paint_tree(int a,int b,int l,int r,int root,int color)
{
	if(a==l&&b==r)
	{
		color_tree[root].color=color;
		color_tree[root].lazy=true;
		return;
	}
	if(color_tree[root].lazy)
	{
		color_tree[root].lazy=false;
		color_tree[root<<1].lazy=true;
		color_tree[root<<1].color=color_tree[root].color;
		color_tree[root<<1|1].lazy=true;
		color_tree[root<<1|1].color=color_tree[root].color;
	}
	int mid=(l+r)>>1;
	if(a>mid) paint_tree(a,b,mid+1,r,root<<1|1,color);
	else if(b<=mid) paint_tree(a,b,l,mid,root<<1,color);
	else 
	{
		paint_tree(a,mid,l,mid,root<<1,color);			
		paint_tree(mid+1,b,mid+1,r,root<<1|1,color);
	}
	color_tree[root].color=color_tree[root<<1].color|color_tree[root<<1|1].color;
}

int diff_tree(int a,int b,int l,int r,int root)
{
	if(color_tree[root].lazy) return color_tree[root].color;//很重要节省大量时间
	if(a==l&&b==r) return color_tree[root].color;
	int mid=(l+r)>>1;
	if(a>mid) return diff_tree(a,b,mid+1,r,root<<1|1);
	else if(b<=mid) return diff_tree(a,b,l,mid,root<<1);
	else return diff_tree(a,mid,l,mid,root<<1)|diff_tree(mid+1,b,mid+1,r,root<<1|1);
}

int count_bit(int a)
{
	int x=1,ans=0;
	for(int i=0;i<32;i++,x<<=1)
	{
		if(x&a) ans++;
	}
	return ans;
}
int main()
{
	int l,t,cases;
	scanf("%d%d%d",&l,&t,&cases);
	make_tree(1,l,1);
	while(cases--)
	{
		getchar();//很重要！切记以后scanf("%c",&char);的时候要考虑这一点.争取以后不用调这个bug,一次过.
		char op;
		scanf("%c",&op);
		if(op=='C')
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(a>b) swap(a,b);
			paint_tree(a,b,1,l,1,1<<(c-1));
		}
		else if(op=='P')
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",count_bit(diff_tree(a,b,1,l,1)));
		}
	}
	return 0;
}