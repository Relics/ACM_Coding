#include <iostream>
using namespace std;

int main()
{
	int X,Y;
	int N;
	int i;
	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>X>>Y;
		if(X>=Y)
			cout<<"MMM BRAINS"<<endl;
		else
			cout<<"NO BRAINS"<<endl;
	}
	return 0;
}