#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int milk[10010];

int main()
{
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&milk[i]);
	}
	sort(milk+1,milk+N+1);
	int m=N/2+1;
	printf("%d\n",milk[m]);
	return 0;
}
