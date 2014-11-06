#include <iostream>
using namespace std;

//o is for left parentheses
//1	is for rigtht parentheses
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int p[21];
		int w[21];
		int str[42];
		int n;
		cin>>n;
		p[0]=0;
		for(int i=1;i<=n;i++)
			cin>>p[i];
		int i,j=1,k;
		for(i=1;i<=n;i++)
		{
			int length=p[i]-p[i-1];
			for(k=1;k<=length;k++)
			{
				str[j]=0;
				j++;
			}
			str[j]=1;
			j++;
		}//找出原始序列
		const int strlength=j-1;
		int count;
		for(i=1;i<=strlength;i++)
		{
			count=1;
			if(str[i]==1)
			{
				for(j=i-1;j>0;j--)
				{
					if(str[j]==0)
					{
						str[j]='F';
						break;
					}
					if(str[j]=='F')
					{
						count++;
					}
				}
			}
			else
				continue;
			cout<<count<<" ";
		}
		cout<<endl;
	}
	return 0;
}