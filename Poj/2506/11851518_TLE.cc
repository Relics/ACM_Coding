#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct
{
	int a[1000];
	int length;
}Big_number;

Big_number b[260];

void add(int n)
{
	b[n].length=b[n-1].length;
	int len=b[n-1].length;
	for(int i=0;i<len;i++)
	{
		b[n].a[i]=b[n-1].a[i]+(b[n-2].a[i])*2;
	}
	for(int i=0;i<len;i++)
	{
		if(b[n].a[i]>9)
		{
			b[n].a[i+1]+=b[n].a[i]/10;
			b[n].a[i]%=10;
		}
	}
	while(b[n].a[len])
	{
		if(b[n].a[len]>9)
		{
			b[n].a[len+1]+=b[n].a[len]/10;
			b[n].a[len]%=10;
			len++;
			b[n].length++;
		}
	}
}

int main()
{
	//memset(b,1,sizeof(b));这句话没有任何意义,不可以对struct类型的数据直接memset.
	b[0].length=1;
	b[0].a[0]=1;
	b[1].length=1;
	b[1].a[0]=1;
	for(int i=2;i<=250;i++)
	{
		add(i);
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int len=b[n].length;
		for(int i=len-1;i>=0;i--)
		{
			printf("%d",b[n].a[i]);
		}
		printf("\n");
	}
	return 0;
}