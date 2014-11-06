#include <iostream>
#include <cmath>
using namespace std;

int n;
double x[1001];
double y[1001];
void bubblesort()
{
	int i,j;
	bool flag=false;
	int temp;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(x[j]>x[j+1])
			{
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
				temp=y[j];
				y[j]=y[j+1];
				y[j+1]=temp;
				flag=true;
			}
		}
		if(!flag)
			break;
	}
}
int main()
{
	int count=1;
	int CircleNumber=1;
	for(;;)
	{
		int i;
		int flag=false;
		double d;
		cin>>n>>d;
		if(n==0&&d==0)
			break;
		for(i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i];
			if(y[i]>d)
				flag=true;	
		}
		if(flag)
		{
			cout<<"Case "<<count++<<": "<<-1<<endl;
			//count++;
		}
		bubblesort();
		double left,right,tempright;
		tempright=x[1]+sqrt(d*d-y[1]*y[1]);
		for(i=2;i<=n;i++)
		{
			left=x[i]-sqrt(d*d-y[i]*y[i]);
			right=x[i]+sqrt(d*d-y[i]*y[i]);
			if(left<=tempright)
				continue;
			else
			{
				tempright=right;
				CircleNumber++;
			}
		}
		cout<<"Case "<<count++<<": "<<CircleNumber<<endl;
		//count++;
		CircleNumber=1;
	}
	return 0;
}