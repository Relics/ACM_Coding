#include <iostream>
using namespace std;

const int Max=12500000;
char count[2*Max+1];

int main()
{
    memset(count,0,sizeof(count));
    int a1,a2,a3,a4,a5;
    int x1,x2,x3,x4,x5;
    unsigned int sum;
    int ans=0;
    cin>>a1>>a2>>a3>>a4>>a5;
    for(x1=-50;x1<=50;x1++)
    {
        if(x1==0)
            continue;
        for(x2=-50;x2<=50;x2++)
        {
            if(x2==0)
                continue;
            sum=(a1*x1*x1*x1+a2*x2*x2*x2)*(-1);
			count[sum+Max]++;
        }
    }
    for(x3=-50;x3<=50;x3++)
    {
        if(x3==0)
            continue;
        for(x4=-50;x4<=50;x4++)
        {
            if(x4==0)
                continue;
            for(x5=-50;x5<=50;x5++)
            {    
                if(x5==0)
                    continue;
                sum=a3*x3*x3*x3+a4*x4*x4*x4+a5*x5*x5*x5;
                if(sum<Max)
					ans+=count[sum+Max];
            }    
        }
    }
    cout<<2*ans<<endl;
    //system("pause");
    return 0;
}