#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char begin[101];
	int sum[101];//这个要学着点啊！SO good
	int length;
	int i,j;
	int base,next;
	for(i=0;i<101;i++)
		sum[i]=0;
	while(cin>>begin)//so good
	{
		length=strlen(begin);
		if(strcmp(begin,"0")==0)
			break;
		i=length-1;
		j=100;
		next=0;
		for(;i>=0;i--)
		{
			sum[j]+=begin[i]-'0'+next;
			next=sum[j]/10;
			sum[j]=sum[j]%10;
			j--;
		}
		if(next>0)
		{
			sum[j]+=next;
			while(sum[j]>9)
			{
				next=sum[j]/10;
				sum[j]=sum[j]%10;
				j--;
				sum[j]+=next;
			}
		}
	}
	i=0;
	while(i!=100&&sum[i]==0)
		i++;
	for(j=i;j<101;j++)
		cout<<sum[j];
	cout<<endl;
	
	return 0;
}