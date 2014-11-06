#include <cstdio>
#include <algorithm>
using namespace std;
const int maxnum=1500;
int a[1500]={1};
int main()
{
    int m=1,n,i=0,j=0,k=0;
    for(;m<maxnum;)
    {
        a[m++]=min(a[i]*2,min(a[j]*3,a[k]*5));
        if(a[m-1]==a[i]*2) ++i;
        if(a[m-1]==a[j]*3) ++j;
        if(a[m-1]==a[k]*5) ++k;
    }
    while(~scanf("%d",&n),n)
        printf("%d\n",a[n-1]);
    return 0;
}
