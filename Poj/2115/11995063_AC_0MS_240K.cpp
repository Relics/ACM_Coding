#include <iostream>
#include <cstdio>
using namespace std;

long long exd_gcd(long long a,long long b,long long &x,long long&y)
{
    long long temp,ret;
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    ret=exd_gcd(b,a%b,x,y);
    temp=x;
    x=y;
    y=temp-a/b*y;
    return ret;
}
int main()
{
    long long A,B,C;
    int k;
    while(scanf("%I64d%I64d%I64d%d",&A,&B,&C,&k)!=EOF&&!(A==0&&B==0&&C==0&&k==0))
    {
        long long D=1LL<<k;
        long long K=B-A;
        long long x,y;
        long long gcd=exd_gcd(C,D,x,y);
        if(K%gcd) 
			printf("FOREVER\n");
        else
		{
			x=(K/gcd)*x;
			cout<<(x%(D/gcd)+(D/gcd))%(D/gcd)<<endl;
		}
    }
    return 0;
}
