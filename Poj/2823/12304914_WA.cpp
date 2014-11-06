#include <iostream>
#include <algorithm>
#include <cstdio>
#define mid ((l+r)>>1)
#define lson (root<<1)
#define rson (root<<1|1)
using namespace std;
const int maxnum=1e6+100;
struct Node
{
    int l,r;
    int val;
    int _max;
    int _min;
}tree[3*maxnum];

void build_tree(int l,int r,int root)
{
    tree[root].l=l;
    tree[root].r=r;
    if(l==r)
        return;
    else
    {
        build_tree(l,mid,lson);
        build_tree(mid+1,r,rson);
    }
}

void update_point(int value,int position,int root)
{
    int l=tree[root].l;
    int r=tree[root].r;
    if(l==r)
    {
        tree[root].val=value;
        tree[root]._max=value;
        tree[root]._min=value;
    }
    else
    {
        if(position<=mid) update_point(value,position,lson);
        else if(position>mid) update_point(value,position,rson);
        tree[root]._max=max(tree[lson]._max,tree[rson]._min);
        tree[root]._min=min(tree[lson]._min,tree[rson]._min);
    }
}

int max_ans;
int min_ans;
bool flag;

void query_interval(int ql,int qr,int root)
{
    int l=tree[root].l;
    int r=tree[root].r;
    if(l==ql&&r==qr)
    {
        if(flag)
        {
            max_ans=tree[root]._max;
            min_ans=tree[root]._min;
            flag=false;
        }
        else
        {
            max_ans=max(max_ans,tree[root]._max);
            min_ans=min(min_ans,tree[root]._min);
        }
    }
    else
    {
        if(qr<=mid)
        {
            query_interval(ql,qr,lson);
        }
        else if(ql>mid)
        {
            query_interval(ql,qr,rson);
        }
        else
        {
            query_interval(ql,mid,lson);
            query_interval(mid+1,qr,rson);
        }
    }
}
int ans1[maxnum];
int ans2[maxnum];
int main()
{
    //freopen("input.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    if(k>n) k=n;
    build_tree(1,n,1);
    for(int i=1;i<=n;++i)
    {
        int temp;
        scanf("%d",&temp);
        update_point(temp,i,1);
    }
    for(int i=1;i<=n-k+1;++i)
    {
        flag=true;
        query_interval(i,i+k-1,1);
        ans1[i]=min_ans;
        ans2[i]=max_ans;
    }
    int i;
    for(i=1;i<=n-k;++i)
        printf("%d ",ans1[i]);
    printf("%d\n",ans1[i]);
    for(i=1;i<=n-k;++i)
        printf("%d ",ans2[i]);
    printf("%d\n",ans2[i]);
    return 0;
}
