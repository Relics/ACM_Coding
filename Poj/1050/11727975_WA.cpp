#include <iostream>
using namespace std;

int a[101][101];
int temp[101];
int n;
int dp()
{
	int dpmax=temp[1];
	int realmax=temp[1];
	for(int i=2;i<=n;i++)
	{
		if(dpmax<0)
		{
			dpmax=temp[i];
		}
		else
		{
			dpmax+=temp[i];
		}
		if(dpmax>realmax)
			realmax=dpmax;
	}	
	return realmax;
}

int main()
{
	int i,j;
	int m,k;
	int dpmax;
	int ans=-1000;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)		//i代表起始行
		for(j=1;j<=n&&j>=i;j++)	//j代表结束行
		{
			memset(temp,0,sizeof(temp));
			for(m=1;m<=n;m++)
			{
				for(k=i;k<=j;k++)
				{
					temp[m]+=a[k][m];
				}
			}
			dpmax=dp();
			if(dpmax>ans)
				ans=dpmax;
		}
	cout<<ans<<endl;
	//system("pause");
	return 0;
}