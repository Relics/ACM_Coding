#include <iostream>
#include <cstdio>
using namespace std;
const int maxnum=1e6+100;

int a[maxnum];

struct my_queue
{
    int value;
    int index;
};

my_queue _min[maxnum];
my_queue _max[maxnum];
inline bool scan_d(int &num)
{
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF)
        return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-')   { IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9')
    {
        num*=10,num+=in-'0';
    }
    if(IsN)
        num=-num;
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        scan_d(a[i]);
    if(m>n) m=n;
    int head=1;
    int tail=1;
    _min[1].value=_max[1].value=a[1];
    _min[1].index=_max[1].index=1;
    for(int i=2;i<=m;++i)
    {
        while(tail>=head&&a[i]<=_min[tail].value)
            --tail;
        _min[++tail].index=i;
        _min[tail].value=a[i];
    }
    printf("%d",_min[head].value);
    for(int i=m+1;i<=n;++i)
    {
        if(_min[head].index<(i-m+1)) ++head;
        while(tail>=head&&a[i]<=_min[tail].value)
            --tail;
        _min[++tail].index=i;
        _min[tail].value=a[i];
        printf(" %d",_min[head].value);
    }
    printf("\n");
    head=tail=1;
    for(int i=2;i<=m;++i)
    {
        while(tail>=head&&a[i]>=_max[tail].value)
            --tail;
        _max[++tail].index=i;
        _max[tail].value=a[i];
    }
    printf("%d",_max[head].value);
    for(int i=m+1;i<=n;++i)
    {
        if(_max[head].index<(i-m+1)) ++head;
        while(tail>=head&&a[i]>=_max[tail].value)
            --tail;
        _max[++tail].index=i;
        _max[tail].value=a[i];
        printf(" %d",_max[head].value);
    }
    printf("\n");
    return 0;
}
