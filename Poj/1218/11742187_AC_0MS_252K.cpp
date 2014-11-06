#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		double a;
		cin>>a;
		cout<<(int)sqrt(a)<<endl;
	}
	return 0;
}