#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[10000100]={1};
int main()
{
    ll p1,p2,p3,m;
    while(cin>>p1>>p2>>p3>>m)
    {
        int i=0,j=0,k=0,n;
        for(n=1;n<=m;)
        {
            a[n++]=min(a[i]*p1,min(a[j]*p2,a[k]*p3));
            if(a[n-1]==a[i]*p1) ++i;
            if(a[n-1]==a[j]*p2) ++j;
            if(a[n-1]==a[k]*p3) ++k;
        }
        cout<<a[n-1]<<endl;
    }
    return 0;
}
