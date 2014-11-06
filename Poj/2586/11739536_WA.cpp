//这代码着实丑陋，编译器见谅

#include <iostream>
using namespace std;

int main()
{
	int s,d;
	int sum;
	bool flag=false;
	while(cin>>s>>d)
	{
	if(s>=4*d)
	{
		flag=true;
	}
	else if(s<0.25*d)
	{
		sum=10*s-2*d;	
		if(sum<0)
			flag=true;
	}
	else if(s<2.0/3*d)
	{
		sum=8*s-4*d;
		if(sum<0)
			flag=true;
	}
	else if(s<1.5*d)
	{
		sum=6*s-6*d;
		if(sum<0)
			flag=true;
	}
	else if(s<4*d)
	{
		sum=3*s-9*d;
		flag=true;
	}
	if(flag)
	{
		cout<<"Deficit"<<endl;
	}
	else
	{
		cout<<sum<<endl;
	}
	flag=false;
	}

	return 0;
}