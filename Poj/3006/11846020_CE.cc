#include <iostream>
using namespace std;

bool is_prime(int temp)
{
	int factor;
	bool flag=true;
	if(temp==2)
		flag=true;
	else if(temp==1||temp%2==0)
		flag=false;
	else
	{
		int m=(int)(sqrt((double)temp)+0.5);
		for(factor=3;factor<=m;factor+=2)
		{
			if(temp%factor==0)
			{
				flag=false;
				break;
			}
		}
	}
	return flag;
}

int main()
{
	for(;;)
	{
		int a,d,n;
		int temp;
		int count=0;
		cin>>a>>d>>n;
		if(a==0&&d==0&&n==0)
			break;
		for(int i=0;count!=n;i++)
		{
			temp=a+i*d;
			if(is_prime(temp))
				count++;
		}
		cout<<temp<<endl;	
	}
	return 0;
}