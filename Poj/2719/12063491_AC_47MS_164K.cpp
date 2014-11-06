#include <cstdio>
using namespace std;

char a[20];
int ans;
void cal(int n)
{
    int cnt=0;
    while(n)
    {
        a[cnt++]=n%10+'0';
        if(a[cnt-1]>'4') a[cnt-1]-=1;
        n/=10;
    }
    for(int i=cnt-1;i>=0;--i)
    {
        ans*=9;
        ans+=a[i]-'0';
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        ans=0;
        cal(n);
        printf("%d: %d\n",n,ans);
    }
    return 0;
}
