#include <cstdio>
#include <algorithm>
using namespace std;
const int maxnum=220;
typedef struct
{
    int l,r;
    int cover;
    double ll,rr;
    double len;
}Node;

typedef struct
{
    double x1,x2,y;
    int flag;
}scanlen;

Node tree[maxnum*4];
scanlen len[maxnum];
double hash[maxnum];

bool mycompare(scanlen a,scanlen b)
{
    return a.y<b.y;
}

void build(int root,int l,int r)
{
    tree[root].l=l;tree[root].ll=hash[l];
    tree[root].r=r;tree[root].rr=hash[r];
    tree[root].cover=0;
    tree[root].len=0.00;
    if(l+1==r) return;
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid,r);
}

void update(int root,scanlen a)
{
    if(tree[root].ll==a.x1&&tree[root].rr==a.x2)
        tree[root].cover+=a.flag;
    else
    {
        int mid=(tree[root].l+tree[root].r)>>1;
        if(a.x1>=hash[mid]) update(root<<1|1,a);
        else if(a.x2<=hash[mid]) update(root<<1,a);
        else
        {
            double temp;
            temp=a.x2;
            a.x2=hash[mid];
            update(root<<1,a);
            a.x2=temp;
            temp=a.x1;
            a.x1=hash[mid];
            update(root<<1|1,a);
            a.x1=temp;
        }
    }
    if(tree[root].cover)
        tree[root].len=tree[root].rr-tree[root].ll;
    else
        tree[root].len=tree[root<<1].len+tree[root<<1|1].len;
}


int main()
{
    int n,cases=1;
    while(scanf("%d",&n),n)
    {
        int m=1,z=2;
        double x1,y1,x2,y2,ans=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            len[m].x1=x1;
            len[m].x2=x2;
            len[m].y=y1;
            len[m].flag=1;
            hash[m++]=x1;
            len[m].x1=x1;
            len[m].x2=x2;
            len[m].y=y2;
            len[m].flag=-1;
            hash[m++]=x2;
        }
        --m;
        sort(len+1,len+1+m,mycompare);
        sort(hash+1,hash+1+m);
        for(int i=2;i<=m;++i)
            if(hash[i]!=hash[i-1]) hash[z++]=hash[i];
        --z;
        build(1,1,z);
        update(1,len[1]);
        for(int i=2;i<=m;++i)
        {
            ans+=tree[1].len*(len[i].y-len[i-1].y);
            update(1,len[i]);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n",cases++,ans);
    }
    return 0;
}
