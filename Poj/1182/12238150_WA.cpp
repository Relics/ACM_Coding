#include <iostream>
#include <cstdio>
using namespace std;
const int maxnum=5e4+100;

int fa[maxnum];//每个点所属的集合的祖先
int relation[maxnum];//每个点与每个点上一级的关系
int rank[maxnum];//记录每个点所属集合的秩，即最大高度
void initial(int n)
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;//初始时所有的元素分别构成一个集合
        rank[i]=0;//初始时所有点所属树的高度为0
        relation[i]=0;//初始时自己也是祖先，当然和祖先同类
    }
}
int father(int x)
{
    if(x!=fa[x])
    {
        int oldfa=fa[x];
        fa[x]=father(fa[x]);
        relation[x]=(relation[x]+relation[oldfa])%3;
    }
    return fa[x];
}

void union_set(int x,int y,int d)
{
    int a=father(x);
    int b=father(y);
    if(a==b)return;
    if(rank[a]>rank[b])
    {
        fa[b]=a;
        int ans=0;
        if(relation[x]==1) ans+=1;
        else if(relation[x]==2) ans-=1;
        if(relation[y]==1) ans-=1;
        else if(relation[y]==2) ans+=1;
        relation[b]=(ans-(d-1)+6)%3;
    }
    else
    {
        fa[a]=b;
        if(rank[a]==rank[b]) ++rank[b];
        int ans=0;
        if(relation[y]==1) ans+=1;
        else if(relation[y]==2) ans-=1;
        if(relation[x]==1) ans-=1;
        else if(relation[x]==2) ans+=1;
        relation[b]=(ans+(d-1)+6)%3;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    int n,k;
    int ans=0;
    scanf("%d%d",&n,&k);
    initial(n);
    for(int i=1;i<=k;++i)
    {
        int d,x,y;
        scanf("%d%d%d",&d,&x,&y);
        if(x>n||y>n) ++ans;
        else if(x==y&&d==2) ++ans;
        else
        {
            int a=father(x),b=father(y);
            if(a==b)
            {
                if(1==d)
                {
                    if(relation[x]!=relation[y])
                        ++ans;
                }
                else if(2==d)
                {
                    if(relation[y]!=(relation[x]+2)%3)
                        ++ans;
                }
            }
            else
            {
                union_set(x,y,d);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

