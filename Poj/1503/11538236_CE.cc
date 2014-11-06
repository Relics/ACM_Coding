#include <iostream>
#include <cstring>
using namespace std;

int main(){
	//char begin[101];
	char begin[110][110];
	int sum[110];//这个要学着点啊！SO good
	int length;
	int i,j;
	int base,next;
	int n=0;
	for(i=0;i<119;i++)
		sum[i]=0;
	while(cin>>begin[n])//so good
	{
		length=strlen(begin[n]);
		if(strcmp(begin[n],"0")==0)
			break;
		i=length-1;
		j=109;
		next=0;
		for(;i>=0;i--)
		{
			sum[j]+=begin[n][i]-'0'+next;
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
		n++;
	}
	i=0;
	while(i!=109&&sum[i]==0)
		i++;
	for(j=i;j<110;j++)
		cout<<sum[j];
	cout<<endl;
	system("pause");
	return 0;
}