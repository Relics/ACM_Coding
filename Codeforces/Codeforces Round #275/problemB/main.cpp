//二分也要优雅的啊
//mid=l+(r-l)/2
//mid=(r+l)>>1
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int cnt1,cnt2,x,y;
    while(scanf("%d%d%d%d",&cnt1,&cnt2,&x,&y)==4){
        int l=1;
        int r=2e9;
        while(l<r){
            int mid=l+(r-l)/2;
            if((mid-mid/x)>=cnt1&&(mid-mid/y)>=cnt2&&(mid-mid/(x*y))>=(cnt1+cnt2)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        printf("%d\n",r);
    }
    return 0;
}
