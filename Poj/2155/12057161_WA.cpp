#include <cstdio>
#include <cstring>
using namespace std;
char matrix[1010][1010];
int n;//matrix的实际大小
int lowbit(int t)
{
    return t&(-t);
}

void add(int x,int y,int adder)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            matrix[i][j]+=adder;
}

long long query(int x,int y)//看似区间求和实际上是查询一个点的值
{
    long long sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            sum+=matrix[i][j];
    return sum;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(matrix,0,sizeof(matrix));
        int m;
        scanf("%d%d",&n,&m);
        while(m--)
        {
            getchar();
            char c;
            scanf("%c",&c);
            if(c=='C')
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                add(x1,y1,1);
                add(x1,y2+1,-1);
                add(x1,y2+1,-1);
                add(x2+1,y2+1,1);
            }
            else if(c=='Q')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",query(x,y)%2);
            }
        }
        if(T) printf("\n");//it's beautiful!
    }
    return 0;
}
