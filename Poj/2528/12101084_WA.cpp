#include <iostream>
#include <cstdio>
#include <algorithm>
#define mid ((l+r)>>1)
#define lson (root<<1)
#define rson (root<<1|1)
using namespace std;
const int maxnum=10100;

struct query
{
    int ql,qr;
}q[maxnum];

struct Node
{
    int l,r;
    int color;
}tree[maxnum*6];

int color[maxnum];
int a[maxnum*2];
int x[maxnum*2];
void build(int l,int r,int root)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].color=0;
    if(l!=r)
    {
        build(l,mid,lson);
        build(mid+1,r,rson);
    }
}

void update(int color,int ql,int qr,int root)
{
    int l=tree[root].l,r=tree[root].r;
    if(ql==l&&qr==r)
    {
        tree[root].color=color;
    }
    else
    {
        if(tree[root].color>0)
        {
            tree[lson].color=tree[root].color;
            tree[rson].color=tree[root].color;
            tree[root].color=0;
        }
        if(ql>mid) update(color,ql,qr,rson);
        else if(qr<=mid) update(color,ql,qr,lson);
        else
        {
            update(color,ql,mid,lson);
            update(color,mid+1,qr,rson);
        }
    }
}

int ans;
void cal(int root)
{
    int l=tree[root].l,r=tree[root].r;
    if(tree[root].color>0)
    {
        if(color[tree[root].color]==0)
        {
            color[tree[root].color]=1;
            ++ans;
        }
    }
    else
    {
        if(l==r) return;
        else
        {
            cal(lson);
            cal(rson);
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int num=1;
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&q[i].ql,&q[i].qr);
            a[num++]=q[i].ql;
            a[num++]=q[i].qr;
        }
        num=1;
        sort(a+1,a+1+2*n);
        x[1]=a[1];
        for(int i=2;i<=2*n;++i) if(a[i]!=a[i-1]) x[++num]=a[i];
        build(1,num,1);
        for(int i=1;i<=n;++i)
        {
            update(i,lower_bound(x+1,x+1+num,q[i].ql)-x,lower_bound(x+1,x+1+num,q[i].qr)-x,1);
        }
        ans=0;
        cal(1);
        printf("%d\n",ans);
    }
    return 0;
}
