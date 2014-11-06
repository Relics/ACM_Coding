#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxnum=1e6+100;

struct queue
{
    int index;
    int value;
};

queue min_ans[maxnum];
queue max_ans[maxnum];
int a[maxnum];

int main()
{
    //freopen("input.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    if(k>n) k=n;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }
    int head=1,tail=1;
    min_ans[1].value=a[1];
    min_ans[1].index=1;
    max_ans[1].value=a[1];
    max_ans[1].index=1;
    for(int i=2;i<=k;++i)
    {
        while(head<=tail&&a[i]<=min_ans[tail].value)
        {
            --tail;
        }
        ++tail;
        min_ans[tail].value=a[i];
        min_ans[tail].index=i;
    }
    printf("%d",min_ans[head].value);
    for(int i=k+1;i<=n;++i)
    {
        while(head<=tail&&a[i]<=min_ans[tail].value)
        {
            --tail;
        }
        ++tail;
        min_ans[tail].value=a[i];
        min_ans[tail].index=i;
        if(min_ans[head].index<=i-k) ++head;
        printf(" %d",min_ans[head].value);
    }
    printf("\n");

    for(int i=2;i<=k;++i)
    {
        while(head<=tail&&a[i]>=max_ans[tail].value)
        {
            --tail;
        }
        ++tail;
        max_ans[tail].value=a[i];
        max_ans[tail].index=i;
    }
    printf("%d",max_ans[head].value);
    for(int i=k+1;i<=n;++i)
    {
        while(head<=tail&&a[i]>=max_ans[tail].value)
        {
            --tail;
        }
        ++tail;
        max_ans[tail].value=a[i];
        max_ans[tail].index=i;
        if(max_ans[head].index<=i-k) ++head;
        printf(" %d",max_ans[head].value);
    }
    printf("\n");
    return 0;
}
