#include <iostream>
#include <cstdio>
using namespace std;
const int maxnum=500100;

int a[maxnum];
int temp[maxnum];
long long ans;
void merge_array(int first,int mid,int last)
{
	int i=first,j=mid+1,k=0;
	int length_left=mid-first+1;
	while(i<=mid&&j<=last)
	{
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else
		{
			ans+=length_left-(i-first);
			temp[k++]=a[j++];
		}
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=last)
		temp[k++]=a[j++];
	for(i=0;i<k;i++)
	{	
		a[first+i]=temp[i];
	}
	return;
}
void merge_sort(int first,int last)
{
	if(first<last)
	{
		int mid=(first+last)/2;
		merge_sort(first,mid);
		merge_sort(mid+1,last);
		merge_array(first,mid,last);
	}
	return;
}

int main()
{
	for(;;)
	{
		ans=0;
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		merge_sort(0,n-1);
		printf("%I64d\n",ans);
	}
	return 0;
}

