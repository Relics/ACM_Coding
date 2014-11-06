#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		char a[3],b[3];
		cin>>a>>b;
		int x,y;
		x=abs(a[0]-b[0]);
		y=abs(a[1]-b[1]);
		if(x==0&&y==0)
		{
			cout<<"0 0 0 0"<<endl;
			continue;
		}
		cout<<min(x,y)+abs(x-y);
		if(x==y||x==0||y==0)
			cout<<" "<<1;
		else
			cout<<" "<<2;
		if(x==0||y==0)
			cout<<" "<<1;
		else
			cout<<" "<<2;
		if(x==y)
			cout<<" "<<1<<endl;
		else
			if((x-y)%2==0)
				cout<<" "<<2<<endl;
			else
				cout<<" Inf"<<endl;
	}
	return 0;
}