#include <iostream>
#include <algorithm>
using namespace std;

int solve(int *time,int N);
int main()
{
	int cost;
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int time[1100];
		int N;
		cin>>N;
		for(int j=1;j<=N;j++)
			cin>>time[j];
		sort(time+1,time+N+1);
		cost=solve(time,N);
		cout<<cost<<endl;
	}
	return 0;
}

int solve(int *time,int N)
{
	int n=N;
	int cost=0;
	while(n>3)
	{
		if((time[n]+time[n-1]+time[1]*2)<(time[n]+time[1]+time[2]*2))
			cost+=time[n]+time[n-1]+time[1]*2;
		else
			cost+=time[n]+time[1]+time[2]*2;
		n-=2;
	}
	if(n==3)
		return cost+=time[1]+time[2]+time[3];	
	if(n==2)
		return cost+=time[2];
	if(n==1)
		return cost+=time[1];
}