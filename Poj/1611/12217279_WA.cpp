#include <cstdio>
using namespace std;
const int maxnum=3e4+100;//结点数目上届

int pa[maxnum];//pa存储的是每个节点的父亲
int rank[maxnum];//rank存储的是每个集合形成的树的高度
int num[maxnum];//num存储的是每个集合中的元素的数量

void initial(int n) //初始化全部集合信息
{
    for(int i=0;i<n;++i)
    {
        pa[i]=i;
        rank[i]=0;
        num[i]=1;
    }
}

int grand_pa(int x) //寻找x的祖先
{
    if(x!=pa[x])
        pa[x]=grand_pa(pa[x]);
    return pa[x];
}

void union_set(int x,int y)//将x和y两个元素所属的元素集合合并
{
    int a=grand_pa(x);
    int b=grand_pa(y);
    if(rank[a]>rank[b])
    {
        pa[b]=a;
        num[a]+=num[b];
    }
    else
    {
        pa[a]=b;
        if(rank[a]==rank[b]) //如果二者高度相等，就把树的高度加一
            ++rank[b];
        num[b]+=num[a];
    }
}

int main()
{
    int m,n;
    while(~scanf("%d%d",&m,&n))
    {
        if(m==0&&n==0) break;
        initial(m);
        for(int i=0;i<n;++i)
        {
            int size;
            scanf("%d",&size);
            int first;
            scanf("%d",&first);
            for(int j=1;j<size;++j)
            {
                int temp;
                scanf("%d",&temp);
                union_set(first,temp);
            }
        }
        printf("%d\n",num[grand_pa(0)]);
    }
    return 0;
}
