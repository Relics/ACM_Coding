#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const int maxnum=3e4+100;

int hehe[maxnum];

multiset<int> a;
multiset<int> b;
int main()
{
    //freopen("input.txt","r",stdin);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",&hehe[i]);
    int num=1;
    for(int i=1;i<=q;++i)
    {
        int t;
        scanf("%d",&t);
        while(t>=num)
        {
            if(!b.empty())
            {
                multiset<int>::iterator b_it=b.end();
                --b_it;   //这里一定要注意！要切记，C++有太多的东西是左闭右开的了!
                if(hehe[num]<*b_it)
                {
                    int temp=*b_it;
                    b.erase(b_it);
                    b.insert(hehe[num]);
                    a.insert(temp);
                }
                else a.insert(hehe[num]);
            }
            else
            {
                a.insert(hehe[num]);
            }
            ++num;
        }
        multiset<int>::iterator a_it=a.begin();
        printf("%d\n",*a_it);
        int temp=*a_it;
        a.erase(a_it);
        b.insert(temp);
    }
    return 0;
}
