#include <cstdio>
#include <algorithm>
using namespace std;
const int maxnum=1e5+100;

int queue[maxnum];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        scanf("%d",&queue[0]);
        int num=0;
        for(int i=2;i<=n;++i)
        {
            int temp;
            scanf("%d",&temp);
            if(temp>queue[num]) queue[++num]=temp;
            else queue[lower_bound(queue,queue+num,temp)-queue]=temp;
        }
        printf("%d\n",num+1);
    }
    return 0;
}
