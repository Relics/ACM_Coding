#include <iostream>
using namespace std;

int main()
{
	int N;
	int r,e,c;
	int i;
	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>r>>e>>c;
		if(r<e-c)
			cout<<"advertise"<<endl;
		else if(r>e-c)
			cout<<"do not advertise"<<endl;
		else
			cout<<"does not matter"<<endl;
	}
	return 0;
}