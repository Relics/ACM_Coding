#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define mid ((l+r)>>1)
#define lson (root<<1)
#define rson (root<<1|1)

using namespace std;
const int maxnum=1e6+100;

struct Node
{
    int l,r;
    int val;
    int lazy;
    int _max,_min;
}tree[maxnum*3];

//建树
void build(int l,int r,int root)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].val=0;
    tree[root]._max=tree[root]._min=0;
    if(l!=r)
    {
        build(l,mid,lson);
        build(mid+1,r,rson);
    }
}

//点更新
void update_point(int value,int position,int root)
{
    int l=tree[root].l,r=tree[root].r;
    if(l==r)
    {
        tree[root].val=value;
        tree[root]._max=tree[root]._min=value;
    }
    else
    {
        if(position<=mid) update_point(value,position,lson);
        else update_point(value,position,rson);
        tree[root]._max=max(tree[lson]._max,tree[rson]._max);
        tree[root]._min=min(tree[lson]._min,tree[rson]._min);
    }
}

//查询点
int query_point(int position,int root)
{
    int l=tree[root].l,r=tree[root].r;
    if(l==r)
    {
        return tree[root].val;
    }
    else
    {
        if(position<=mid) query_point(position,lson);
        else query_point(position,rson);
    }
}

int q_max;
int q_min;
bool flag;
//查询区间
void query_interval(int ql,int qr,int root)
{
    int l=tree[root].l,r=tree[root].r;
    if(ql==l&&qr==r)
    {
        if(flag)
        {
            q_max=tree[root]._max;
            q_min=tree[root]._min;
            flag=false;
        }
        else
        {
            q_max=max(q_max,tree[root]._max);
            q_min=min(q_min,tree[root]._min);
        }
    }
    else
    {
        if(qr<=mid) query_interval(ql,qr,lson);
        else if(ql>mid) query_interval(ql,qr,rson);
        else
        {
            query_interval(ql,mid,lson);
            query_interval(mid+1,qr,rson);
        }
    }
}

int max_ans[maxnum];
int min_ans[maxnum];

int main()
{
    freopen("input.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    if(k>n) k=n;
    build(1,n,1);
    for(int i=1;i<=n;++i)
    {
        int temp;
        scanf("%d",&temp);
        update_point(temp,i,1);
    }
    if(k>n) k=n;
    for(int i=1;i<=n-k+1;++i)
    {
        flag=true;
        int j=i+k-1;
        query_interval(i,j,1);
        max_ans[i]=q_max;
        min_ans[i]=q_min;
    }
    int i;
    for(i=1;i<=n-k;++i)
    {
        printf("%d ",min_ans[i]);
    }
    printf("%d\n",min_ans[i]);
    for(i=1;i<=n-k;++i)
    {
        printf("%d ",max_ans[i]);
    }
    printf("%d\n",max_ans[i]);
    return 0;
}
