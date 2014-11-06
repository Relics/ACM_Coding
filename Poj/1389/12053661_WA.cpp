//poj1389
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxnum=2100;
typedef struct
{
    int l,r;
    int ll,rr;
    int len;
    int cover;
}Node;

typedef struct
{
    int flag;
    int ll,rr,y;
}Scanlen;

Node tree[maxnum*4];
Scanlen len[maxnum];
int x[maxnum];

bool mycompare(Scanlen a,Scanlen b)
{
    return a.y<b.y;
}

void build(int root,int l,int r)
{
    tree[root].l=l,tree[root].r=r;
    tree[root].ll=x[l],tree[root].rr=x[r];
    tree[root].len=tree[root].cover=0;
    if(l+1==r)return;
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid,r);
    return;
}

void insert(Scanlen a,int ll,int rr,int root)
{
    if(tree[root].ll==ll&&tree[root].rr==rr)
        tree[root].cover+=a.flag;
    else
    {
        int mid=(tree[root].l+tree[root].r)>>1;
        if(rr<=x[mid]) insert(a,ll,rr,root<<1);
        else if(ll>=x[mid]) insert(a,ll,rr,root<<1|1);
        else
        {
            insert(a,ll,x[mid],root<<1);
            insert(a,x[mid],rr,root<<1|1);
        }
    }
    if(tree[root].cover>0) tree[root].len=tree[root].rr-tree[root].ll;
    else if(tree[root].l+1==tree[root].r) tree[root].len=0;
    else tree[root].len=tree[root<<1].len+tree[root<<1|1].len;
}
int main()
{
    freopen("input.txt","r",stdin);
    int x1,y1,x2,y2,m=1,n=1;
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF)
    {
        if(x1==-1)
        {
            --m;
            if(m==0) break;
            sort(len+1,len+1+m,mycompare);
            sort(x+1,x+1+m);
            for(int i=2;i<=m;++i) if(x[i]!=x[i-1]) x[++n]=x[i];
            build(1,1,n);
            long long ans=0;
            for(int i=1;i<=m-1;++i)
            {
                insert(len[i],len[i].ll,len[i].rr,1);
                ans+=(long long)tree[1].len*(len[i+1].y-len[i].y);
            }
            printf("%I64d\n",ans);
            m=n=1;
        }
        else
        {
            len[m].ll=x1;
            len[m].rr=x2;
            len[m].y=y1;
            x[m]=x1;
            len[m++].flag=1;
            len[m].ll=x1;
            len[m].rr=x2;
            len[m].y=y2;
            x[m]=x2;
            len[m++].flag=-1;
        }
    }
    return 0;
}
