#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		double distance=y-x;
		int ans;
		ans=int(sqrt(distance)*2-1e-9);
		cout<<ans<<endl;
	}
	return 0;
}