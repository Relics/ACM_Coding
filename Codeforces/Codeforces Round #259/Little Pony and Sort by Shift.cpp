#include <iostream>
#include <cstdio>
using namespace std;
const int max_num=1e5+100;

int a[max_num];
int flag[max_num];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    if(n>=2){
        for(int i=0;i<n;++i){
            int prev=i;
            int next=(i+1)%n;
            if(a[prev]>a[next]){
                flag[next]=1;
                break;
            }
        }
    }
    bool llp=false;
    int ans=-1;
    bool all=true;
    for(int i=0;i<n-1;++i)
        if(a[i]>a[i+1]){
            all=false;
            break;
        }
    if(all)
        ans=0;
    for(int i=n-1;i>=0;--i){
        if(flag[i]==1){
            bool hehe=false;
            for(int j=i;;j=(j+1)%n){
                if(hehe&&j==i-1)
                    llp=true;
                if(!hehe)
                    hehe=true;
                if(a[j]>a[(j+1)%n])
                    break;
            }
        }
        if(llp){
            ans=n-i;
            break;
        }
    }
    cout<<ans<<endl;
}