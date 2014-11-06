#include <iostream>
using namespace std;

int yinzi(int n)
{
    int counts=0;
    while(n!=0)
    {
        counts+=n/2;
        n/=2;
    }
    return counts;
}

int main()
{
    int n,k;
    int a,b,c;
    while(cin>>n>>k)
    {
        a=yinzi(n);
        b=yinzi(k);
        c=yinzi(n-k);
        if(a>b+c)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}
