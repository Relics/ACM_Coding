#include <iostream>
using namespace std;

int main()
{
	float a[300];
	int n;
	a[0]=0;
	a[1]=0.5;
	for(n=2;n<299;n++)
		a[n]=a[n-1]+1/(float)(n+1);
	float c;
	cin>>c;
	while(c!=0.00)
	{
		int i;
		for(i=1;i<299;i++)
		{
			if(a[i]>=c)
			{
				cout<<i<<" card(s)"<<endl;
				break;
			}
		}
		cin>>c;
	}
	return 0;
}