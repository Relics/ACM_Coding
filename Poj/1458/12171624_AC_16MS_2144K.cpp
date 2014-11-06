#include <cstdio>
#include <cstring>
using namespace std;
const int maxnum=1e4;

char a[maxnum];
char b[maxnum];
int f[maxnum][maxnum];
int prin[maxnum][maxnum];


int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%s%s",a,b)!=EOF)
    {
        int m=strlen(a);
        int n=strlen(b);
        //Intialize
        for(int i=0;i<=m;++i)
            f[0][i]=0;
        for(int i=1;i<=n;++i)
            f[i][0]=0;
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
            {
                if(a[i-1]==b[j-1])
                {
                    f[i][j]=f[i-1][j-1]+1;
                    prin[i][j]=0;
                }
                else
                {
                    if(f[i-1][j]>=f[i][j-1])
                    {
                        f[i][j]=f[i-1][j];
                        prin[i][j]=1;
                    }
                    else
                    {
                        f[i][j]=f[i][j-1];
                        prin[i][j]=-1;
                    }
                }
            }
        printf("%d\n",f[m][n]);
    }
    return 0;
}
