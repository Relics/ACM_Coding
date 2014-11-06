#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

#define LEN 32000
unsigned int a[LEN];//第i组的位数长度
unsigned int b[LEN];//到第i组总的位数长度

int main()
{
	a[0]=0;
	a[1]=1;
	b[0]=0;
	b[1]=1;
	int i;
	for(i=2;i<LEN;i++)
	{
		a[i]=a[i-1]+(int)log10((double)i)+1;
		b[i]=b[i-1]+a[i];
	}	int t;
	cin>>t;
	while(t--)
	{
		unsigned int n;
		cin>>n;
		i=0;
		while(b[i]<n)
			i++;
		int position;
		position=n-b[i-1];
		unsigned int c[LEN];
		int j;
		c[0]=0;
		c[1]=1;
		for(j=2;j<=i;j++)
		{
			c[j]=c[j-1]+(int)log10((double)j)+1;
			if(c[j]>=position)
				break;
		}
		position=position-c[j-1];
		char d[100]={0};
		i=0;
		while(j!=0)
		{
			d[i]=j%10+48;
			j/=10;
			i++;
		}
		int length;
		length=strlen(d);
		cout<<d[length-position]<<endl;
	}
	
	return 0;
}