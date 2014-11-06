#include <iostream>
using namespace std;

const double PI=3.1415926;
int main()
{
	int T;
	int N=1;
	cin>>T;
	while(T--)
	{
		int Z=1;
		double X,Y;
		cin>>X>>Y;
		double s1=0.5*PI*(X*X+Y*Y);
		Z=(int)s1/50+1;
		cout<<"Property "<<N<<": This property will begin eroding in year "<<Z<<"."<<endl;
		N++;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
}
