#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

char IP[50];
int quan[8]={128,64,32,16,8,4,2,1};

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		cin>>IP;
		int a=0,b=0,c=0,d=0;
		int i;
		for(i=0;i<=7;i++)
		{
			a+=(IP[i]-'0')*quan[i%8];
		}
		for(i=8;i<=15;i++)
		{
			b+=(IP[i]-'0')*quan[i%8];
		}
		for(i=16;i<=23;i++)
		{
			c+=(IP[i]-'0')*quan[i%8];
		}
		for(i=24;i<=31;i++)
		{
			d+=(IP[i]-'0')*quan[i%8];
		}
		printf("%d.%d.%d.%d\n",a,b,c,d);
	}
	return 0;
}
