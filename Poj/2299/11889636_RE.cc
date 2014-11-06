#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[50100];
int swapnum;

void bubble_sort(int size)
{
	swapnum=0;
	bool flag=false;
	int i,j;
	for(i=0;i<size-1;i++)
	{
		flag=false;
		for(j=0;j<size-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				flag=true;
				swapnum++;
			}
		}
		if(!flag)
			break;
	}
}
int main()
{
	for(;;)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		bubble_sort(n);
		printf("%d\n",swapnum);
	}
	return 0;
}