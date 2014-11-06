#include<iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        int count=0;
        cin>>N;
        while(N!=0)
        {
            count+=N/5;
            N/=5;
        }
        cout<<count<<endl;
    }
    return 0;
}
