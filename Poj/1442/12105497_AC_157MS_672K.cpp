#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxnum=3e4+100;
struct max_heap
{
    int x;
    bool operator<(const max_heap&a) const
    {
        return x<a.x;
    }
};

struct min_heap
{
    int x;
    bool operator<(const min_heap&a) const
    {
        return x>a.x;
    }
};

int a[maxnum];
priority_queue<max_heap> max_h;
priority_queue<min_heap> min_h;
max_heap max_t;
min_heap min_t;

int main()
{
    //freopen("input.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;++i)
        scanf("%d",&a[i]);
    int num=1;
    for(int i=1;i<=n;++i)
    {
        int t;
        scanf("%d",&t);
        while(num<=t)
        {
            if(!max_h.empty()&&max_h.top().x>a[num])
            {
                int temp=max_h.top().x;
                max_h.pop();
                max_t.x=a[num];
                max_h.push(max_t);
                min_t.x=temp;
                min_h.push(min_t);
            }
            else
            {
                min_t.x=a[num];
                min_h.push(min_t);
            }
            ++num;
        }
        printf("%d\n",min_h.top().x);
        int temp=min_h.top().x;
        max_t.x=temp;
        min_h.pop();
        max_h.push(max_t);
    }
    return 0;
}
