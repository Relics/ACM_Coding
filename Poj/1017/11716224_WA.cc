#include <iostream>
using namespace std;

const int a[4]={0,5,3,1};

int main()
{
	int s1,s2,s3,s4,s5,s6;
	cin>>s1>>s2>>s3>>s4>>s5>>s6;
	while(s1!=0||s2!=0||s3!=0||s4!=0||s5!=0||s6!=0)
	{
		int n;
		n=s6+s5+s4+(s3+3)/4;
		
		if(s2>(s4*5+a[s3%4]))
			n+=(s2-s4*5-a[s3%3]+8)/9;
		if(s1>(n*36-s6*36-s5*25-s4*16-s3*9-s2*4))
			n+=(s1-(n*36-s6*36-s5*25-s4*16-s3*9-s2*4)+35)/36;
		cout<<n<<endl;
		cin>>s1>>s2>>s3>>s4>>s5>>s6;
	}
	return 0;
}