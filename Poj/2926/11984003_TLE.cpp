#include <cstdio>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxnum=100010;
double university[maxnum][6];
multiset<double> a[1<<5];

int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;++i)
    {
        for(j=0;j<5;++j)
            scanf("%lf",&university[i][j]);
        for(j=0;j<(1<<5);++j)
        {
            double sum=0;
            for(k=0;k<5;++k)
            {
                if(j&(1<<k)) sum+=university[i][k];
                else sum-=university[i][k];
            }
            a[j].insert(sum);
        }
    }
    double _max;
    for(j=0;j<(1<<5);++j)
    {
        multiset <double>::iterator it1,it2;
        it1=a[j].begin();
        it2=a[j].end();
        --it2;
        _max=max(_max,*it2-*it1);
    }
    printf("%.2lf\n",_max);
   // system("pause");
    return 0;
}
