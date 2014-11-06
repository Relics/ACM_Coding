#include <iostream>
using namespace std;

int a[1100],b[1100]={0};
int N,ans=1;
int dp()
{
    b[1]=1;
    for(int i=2;i<=N;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i]&&(b[i]<b[j]+1))
                b[i]=b[j]+1;
        }
        if(b[i]>ans)
            ans=b[i];
    }       
    return ans; 
}

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
            cin>>a[i];
    ans=dp();
    cout<<ans<<endl;
    //system("pause");
    return 0;
}

