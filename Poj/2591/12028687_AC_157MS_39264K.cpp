#include <cstdio>
using namespace std;
const int maxnum=10000100;
int a[maxnum]={1};
int main()
{
    int *x1=a,*x2=a,i;
    int temp1,temp2;
    for(i=1;i<maxnum;)
    {
        temp1=2**x1+1,temp2=3**x2+1;
        if(temp1<temp2) a[i++]=temp1,x1++;
        else if(temp1>temp2) a[i++]=temp2,x2++;
        else a[i++]=temp1,x1++,x2++;
    }
    int n;
    while(~scanf("%d",&n))
        printf("%d\n",a[n-1]);
    return 0;
}
