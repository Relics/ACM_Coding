#include <cstdio>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
const int apex=0x7FFFFFFF;
const int fundus=-0x7FFFFFFF;
double university[6],_max[1<<5],_min[1<<5];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        for(j=0;j<5;++j)
            scanf("%lf",&university[j]);
        for(j=0;j<(1<<5);++j)
        {
            double sum=0;
            for(k=0;k<5;++k)
            {
                if(j&(1<<k)) sum+=university[k];
                else sum-=university[k];
            }
            if(1==i) _max[j]=_min[j]=sum;
            else _max[j]=max(_max[j],sum),_min[j]=min(_min[j],sum);
        }
    }
    double ans=-1;
    for(j=0;j<(1<<5);++j)
        ans=max(ans,_max[j]-_min[j]);
    printf("%.2lf\n",ans);
    system("pause");
    return 0;
}
