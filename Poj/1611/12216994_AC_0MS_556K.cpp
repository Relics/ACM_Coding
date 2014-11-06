#include <iostream>
#include <cstdio>
using namespace std;
const int maxnum=3e4+100;//结点数目上届
int pa[maxnum];//pa[x]表示x的父节点
int rank[maxnum];//rank[x]是x的高度的一个上界
int num[maxnum];//num[]存储在该集合中的元素个数，并在集合合并时更新时更新num[]

void initial(int size)//size为初始化时的集合个数
{
    for(int i=0;i<size;++i)
    {
        pa[i]=i;
        rank[i]=0;
        num[i]=1;
    }
}
//递归版本
int father(int x)//寻找x的老祖先+带路径压缩
{
    if(x!=pa[x]) pa[x]=father(pa[x]);
    return pa[x];
}

void union_set(int x,int y)//union_set(x,y)时,按秩合并,秩小的并给秩大的
{
    int a=father(x);//x的祖先
    int b=father(y);//y的祖先
    if(a==b) return;
    if(rank[a]>rank[b])
    {
        pa[b]=a;
        num[a]+=num[b];
    }
    else if(rank[a]<rank[b])
    {
        pa[a]=b;
        num[b]+=num[a];
    }
    else if(rank[a]==rank[b])
    {
        pa[b]=a;
        num[a]+=num[b];
        ++rank[a];
    }
}


int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n))
    {
        if(m==0&&n==0)break;
        initial(m);//初始化集合。
        for(int i=0;i<n;++i)
        {
            int num,x;
            scanf("%d%d",&num,&x);
            for(int j=1;j<num;++j)
            {
                int y;
                scanf("%d",&y);
                union_set(x,y);
            }
        }
        cout<<num[father(0)]<<endl;
    }
    return 0;
}
