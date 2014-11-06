#include <cstdio>
#include <algorithm>
using namespace std;
const int maxnum=10010;

typedef struct
{
    int l,r;
    int ll,rr;
    int cover;
    int len;
}Nodex;

typedef struct
{
    int h,d;
    int hh,dd;
    int cover;
    int len;
}Nodey;

typedef struct
{
    int flag; //记录出边还是入边
    int x1,x2,y;
}scanlen_x;

typedef struct
{
    int flag; //记录出边还是入边
    int y1,y2,x;
}scanlen_y;

Nodex treex[maxnum*4];
Nodey treey[maxnum*4];
scanlen_x scanx[maxnum];
scanlen_y scany[maxnum];
int x[maxnum];
int y[maxnum];

bool mycomparex(scanlen_x a,scanlen_x b)
{
    return a.y<b.y;
}

bool mycomparey(scanlen_y a,scanlen_y b)
{
    return a.x<b.x;
}

void buildx(int root,int l,int r)
{
    treex[root].l=l;
    treex[root].r=r;
    treex[root].ll=x[l];
    treex[root].rr=x[r];
    treex[root].cover=0;
    treex[root].len=0;
    if(l+1==r) return;
    int mid=(l+r)>>1;
    buildx(root<<1,l,mid);
    buildx(root<<1|1,mid,r);
}

void buildy(int root,int l,int r)
{
    treey[root].d=l;
    treey[root].h=r;
    treey[root].dd=y[l];
    treey[root].hh=y[r];
    treey[root].cover=0;
    treey[root].len=0;
    if(l+1==r) return;
    int mid=(l+r)>>1;
    buildy(root<<1,l,mid);
    buildy(root<<1|1,mid,r);
}

void updatex(scanlen_x a,int l,int r,int root)
{
    if(l==treex[root].ll&&r==treex[root].rr)
        treex[root].cover+=a.flag;
    else
    {
        int mid=(treex[root].l+treex[root].r)>>1;
        if(l>=x[mid]) updatex(a,l,r,root<<1|1);
        else if(r<=x[mid]) updatex(a,l,r,root<<1);
        else
        {
            updatex(a,l,x[mid],root<<1);
            updatex(a,x[mid],r,root<<1|1);
        }
    }
    if(treex[root].cover)
        treex[root].len=treex[root].rr-treex[root].ll;
    else if(treex[root].l+1==treex[root].r)
        treex[root].len=0;
    else
        treex[root].len=treex[root<<1].len+treex[root<<1|1].len;
}
void updatey(scanlen_y a,int d,int h,int root)
{
    if(d==treey[root].dd&&h==treey[root].hh)
        treey[root].cover+=a.flag;
    else
    {
        int mid=(treey[root].d+treey[root].h)>>1;
        if(d>=y[mid]) updatey(a,d,h,root<<1|1);
        else if(h<=y[mid]) updatey(a,d,h,root<<1);
        else
        {
            updatey(a,d,y[mid],root<<1);
            updatey(a,y[mid],h,root<<1|1);
        }
    }
    if(treey[root].cover)
        treey[root].len=treey[root].hh-treey[root].dd;
    else if(treey[root].d+1==treey[root].h)
        treey[root].len=0;
    else
        treey[root].len=treey[root<<1].len+treey[root<<1|1].len;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int i,m=1,k=1;
        for(i=1;i<=n;++i)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            scanx[m].x1=x1;scanx[m].x2=x2;scanx[m].y=y1;scanx[m].flag=1;
            x[m++]=x1;
            scanx[m].x1=x1;scanx[m].x2=x2;scanx[m].y=y2;scanx[m].flag=-1;
            x[m++]=x2;
            scany[k].y1=y1;scany[k].y2=y2;scany[k].x=x1;scany[k].flag=1;
            y[k++]=y1;
            scany[k].y1=y1;scany[k].y2=y2;scany[k].x=x2;scany[k].flag=-1;
            y[k++]=y2;
        }
        --m,--k;
        sort(scanx+1,scanx+m+1,mycomparex);
        sort(x+1,x+m+1);
        sort(scany+1,scany+k+1,mycomparey);
        sort(y+1,y+k+1);
        int o=2,p=2;
        for(i=2;i<=m;++i)
            if(x[i]!=x[i-1]) x[o++]=x[i];
        for(i=2;i<=k;++i)
            if(y[i]!=y[i-1]) y[p++]=y[i];
        --o,--p;
        buildx(1,1,o);//在x轴建立线段树
        buildy(1,1,p);//在y轴建立线段树
        int ans=0,last=0;
        for(i=1;i<=m;++i)
        {
            updatex(scanx[i],scanx[i].x1,scanx[i].x2,1);
            ans+=abs(treex[1].len-last);
            last=treex[1].len;
        }
        last=0;
        for(i=1;i<=k;++i)
        {
            updatey(scany[i],scany[i].y1,scany[i].y2,1);
            ans+=abs(treey[1].len-last);
            last=treey[1].len;
        }
        printf("%d\n",ans);
    }
    return 0;
}
