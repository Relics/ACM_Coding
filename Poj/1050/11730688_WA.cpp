#include <iostream>
#include <algorithm>
using namespace std;

int matrix[101][101];
int line[101];
int N;
int dpmax=-1000;
int dp()
{
	int i,j;
	int max=-1000;
	int temp=line[1];
	for(i=2;i<=N;i++)
	{
		if(line[i-1]<0)
			temp=line[i];
		else
			temp+=line[i];
		if(temp>max)
			max=temp;
	}
	return max;
}

int main()
{
	int i,j;
	int m,n;
	cin>>N;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			cin>>matrix[i][j];
	for(i=1;i<=N;i++)//起始行
	{
		for(j=i;j<=N;j++)//结尾行
		{
			memset(line,0,sizeof(line));
			for(m=1;m<=N;m++)
			{
				for(n=i;n<=j;n++)
				{
					line[m]+=matrix[n][m];
				}
			}
			dpmax=max(dpmax,dp());
		}
	}
	cout<<dpmax<<endl;
	
	return 0;
}