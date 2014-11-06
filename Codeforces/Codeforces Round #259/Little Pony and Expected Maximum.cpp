#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    double ans=0;
    double prev=0;
    for(int i=1;i<=m;++i){
        double now=pow((double)i/(double)m,n);
        ans+=(now-prev)*i;
        prev=now;
    }
    cout<<ans<<endl;
    return 0;
}