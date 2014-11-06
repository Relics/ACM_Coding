#include <iostream>
using namespace std;


int DFS(int M,int N)
{
	if(N==1)
		return 1;
	if(M==0)
		return 1;
	if(N==0)
		return 0;
	if(M>=N)
		return DFS(M,N-1)+DFS(M-N,N);
	else
		return DFS(M,N-1);
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k=0;
		int M,N;
		cin>>M>>N;
		k=DFS(M,N);
		cout<<k<<endl;
	}
	return 0;
}