#include <iostream>
#include <cmath>
using namespace std;
const int maxnum=1e5+100;
int a[maxnum];

int main()
{
    int n,k;
    cin>>n>>k;
    int before=1;
    int cha=k;
    int now;
    int hehe=1;
    a[1]=1;
    for(int i=1;i<=n;++i){
        if(i==1)
            cout<<"1";
        else{
            int temp1=before+cha;
            int temp2=before-cha;
            if(temp2>0){
                if(hehe&&temp1<=n&&a[temp1]==0){
                    a[temp1]=1;
                    cout<<" "<<temp1;
                    before=temp1;
                    hehe=0;
                }else{
                    cout<<" "<<temp2;
                    before=temp2;
                    a[temp2]=1;
                    hehe=1;
                }
            }else{
                cout<<" "<<temp1;
                before=temp1;
                a[temp1]=1;
                hehe=0;
            }
            --cha;
            if(cha==0){
                break;
            }
        }
    }
    for(int i=1;i<=n;++i){
        if(a[i]==0)
            cout<<" "<<i;
    }
    cout<<endl;
}
