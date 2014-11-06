#include <iostream>
#include <cmath>
using namespace std;

int n;
double x[1001];
double y[1001];
double leftx[1001];
double rightx[1001];
void bubblesort()
{
	int i,j;
	bool flag=false;
	double temp;
	//int temp;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(rightx[j]>rightx[j+1])
			{
				temp=rightx[j];
				rightx[j]=rightx[j+1];
				rightx[j+1]=temp;
				temp=leftx[j];
				leftx[j]=leftx[j+1];
				leftx[j+1]=temp;
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
			if(abs(y[i])>d)
				flag=true;	
		}
		if(flag)
		{
			cout<<"Case "<<count++<<": "<<-1<<endl;
			continue;
			//count++;
		}
		for(i=1;i<=n;i++)
		{
			leftx[i]=x[i]-sqrt(d*d-y[i]*y[i]);
			rightx[i]=x[i]+sqrt(d*d-y[i]*y[i]);
		}
		bubblesort();
		double radar=rightx[1];
		for(i=2;i<=n;i++)
		{
			if(radar>=leftx[i])
				continue;
			else
			{
				radar=rightx[i];
				CircleNumber++;
			}
		}
		cout<<"Case "<<count++<<": "<<CircleNumber<<endl;
		//count++;
		CircleNumber=1;
	}
	return 0;
}