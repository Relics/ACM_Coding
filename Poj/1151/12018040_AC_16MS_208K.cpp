#include <cstdio>
#include <algorithm>
using namespace std;
const int maxnum=110;

typedef struct
{
    double len;//实际长度
    int cover;//这里想错了，原来以为是lazy的思想，后来发现不是。
}Node;

typedef struct
{
    double x1,x2,y;
    int flag;
}scanlen;

Node seg_tree[maxnum*8];
scanlen scan[maxnum*2];
double x[maxnum*2];

void build_tree(int root,int l,int r)
{
    seg_tree[root].cover=0;
    seg_tree[root].len=0.00;
    if(l+1==r) return;
    int mid=(l+r)>>1;
    build_tree(root<<1,l,mid);
    build_tree(root<<1|1,mid,r);
}

void cal(int root,int l,int r)
{
    if(seg_tree[root].cover>0)
        seg_tree[root].len=x[r]-x[l];
    else if(l+1==r)
        seg_tree[root].len=0.00;
    else
        seg_tree[root].len=seg_tree[root<<1].len+seg_tree[root<<1|1].len;
}

void update(scanlen a,double lx,double rx,int root,int l,int r)
{
    if(lx==x[l]&&rx==x[r])
        seg_tree[root].cover+=a.flag;
    else
    {
        int mid=(l+r)>>1;
        if(lx>=x[mid]) update(a,lx,rx,root<<1|1,mid,r);
        else if(rx<=x[mid]) update(a,lx,rx,root<<1,l,mid);
        else
        {
            update(a,lx,x[mid],root<<1,l,mid);
            update(a,x[mid],rx,root<<1|1,mid,r);
        }
    }
    cal(root,l,r);
}

bool mycompare(scanlen a,scanlen b)
{
    return a.y<b.y;
}
int main()
{
    int n,cases=1;
    while(scanf("%d",&n)==1,n)
    {
        int i,j=1,k=2;
        double x1,y1,x2,y2,ans=0;
        for(i=1;i<=n;++i)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            scan[j].x1=x1;
            scan[j].x2=x2;
            scan[j].y=y1;
            scan[j].flag=1;
            x[j++]=x1;
            scan[j].x1=x1;
            scan[j].x2=x2;
            scan[j].y=y2;
            scan[j].flag=-1;
            x[j++]=x2;
        }
        --j;
        sort(scan+1,scan+j+1,mycompare);
        sort(x+1,x+j+1);
        for(i=2;i<=j;++i) if(x[i]!=x[i-1]) x[k++]=x[i]; //离散化需要判重！
        --k;
        build_tree(1,1,k);
        update(scan[1],scan[1].x1,scan[1].x2,1,1,k);//先加入第一条边
        for(i=2;i<=j;++i)
        {
            ans+=seg_tree[1].len*(scan[i].y-scan[i-1].y);
            update(scan[i],scan[i].x1,scan[i].x2,1,1,k);//先计算和再更新边
        }
        printf("Test case #%d\n",cases++);
        printf("Total explored area: %.2f\n\n",ans);
    }
    return 0;
}
