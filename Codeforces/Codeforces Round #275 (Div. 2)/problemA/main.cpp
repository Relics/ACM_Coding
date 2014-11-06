//For my love_llp
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxnum=1e5+100;

long long gcd(long long a,long long b)//求最大公约数
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int a[maxnum];

int main()
{
    //freopen("input.txt","r",stdin);
    ll l,r;
    cin>>l>>r;
    for(int i=0;;++i){
        ll a=l+i;
        if(a>r-2)
            break;
        for(int j=1;;++j){
            ll b=a+j;
            if(b>r-1)
                break;
            for(int k=1;;++k){
                ll c=b+k;
                if(c>r)
                    break;
                ll hehe=gcd(a,b);
                ll heihei=gcd(b,c);
                ll haha=gcd(a,c);
                if(hehe==heihei&&haha!=hehe){
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    return 0;
                }
            }
        }
    }
    printf("-1");
    return 0;
}

