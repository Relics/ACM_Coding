#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#define maxlen 10010
using namespace std;

bool flag[maxlen];

int main()
{
	int i;
	memset(flag,false,sizeof(flag));
	for(i=1;i<=10000;i++)
	{
		int m;
		m=i+i%10+i/10%10+i/100%10+i/1000%10;
		flag[m]=true;
	}
	for(i=1;i<=10000;i++)
	{
		if(!flag[i])
			printf("%d\n",i);
	}
	//system("pause");
	return 0;
}
