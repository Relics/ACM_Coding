#include <iostream>
#include <cstdio>
using namespace std;
const int _maxnum=32010;
const int _max=15010;
int star_level[_max];
int star_num[_maxnum];
int lowbit(int t)
{
	return t&(-t);
}
int	sum(int n)
{
	int temp=0;
	while(n>0)
	{
		temp+=star_num[n];
		n=n-lowbit(n);
	}
	return temp;
}
void change(int position,int change_num)
{
	while(position<=_maxnum)	
	{
		star_num[position]+=change_num;
		position=position+lowbit(position);
	}
}
int main()
{	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		star_level[sum(x+1)]++;
		change(x+1,1);
	}
	for(int i=0;i<n;i++)
		printf("%d\n",star_level[i]);
	return 0;
}