#include <iostream>
using namespace std;

int main()
{
	int n;
	for(;;)
	{
		cin>>n;
		if(n==-1)
			break;
		int sum;
		int s;
		int t1;
		int t2;
		cin>>s>>t1;
		sum=s*t1;
		for(int i=1;i<n;i++)
		{
			cin>>s>>t2;
			sum+=s*(t2-t1);
			t1=t2;
		}
		cout<<sum<<" miles"<<endl;
	}
	return 0;
}