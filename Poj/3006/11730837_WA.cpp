#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int temp)
{
	double k=sqrt((double)temp);
	int m=(int)k+1;
	for(int i=2;i<=m;i++)
	{
		if(temp%i==0)
			return false;
	}
	return true;
}

int main()
{
	
	int ans;
	int a,d,n;
	cin>>a>>d>>n;
	while(a!=0||d!=0||n!=0)
	{
		int count=0;
		int temp=a;
		for(int i=0;i<1000000;i++)
		{
			if(isprime(temp))
				count++;
			if(count==n)
			{
				ans=temp;
				break;
			}
			temp+=d;
		}
		cout<<ans<<endl;
		cin>>a>>d>>n;
	}
	return 0;
}