#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int i;
	int index1[17],index2[17],index3[17];
	for(i=1;i<=16;i++)
	{
		cin>>index1[i]>>index2[i]>>index3[i];
	}	
	for(;;)
	{
		double a,b,c;
		int minindex1,minindex2,minindex3;
		cin>>a>>b>>c;
		if(a==-1&&b==-1&&c==-1)
			break;
		double d=1e10;
		for(int i=1;i<=16;i++)
		{
			if(d>sqrt((a-index1[i])*(a-index1[i])+(b-index2[i])*(b-index2[i])+(c-index3[i])*(c-index3[i])))
			{
				d=sqrt((a-index1[i])*(a-index1[i])+(b-index2[i])*(b-index2[i])+(c-index3[i])*(c-index3[i]));
				minindex1=index1[i];
				minindex2=index2[i];
				minindex3=index3[i];
			}
		}
		cout<<"("<<a<<","<<b<<","<<c<<") maps to ("<<minindex1<<","<<minindex2<<","<<minindex3<<")"<<endl;
	}
	return 0;
}