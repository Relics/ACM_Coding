#include <iostream>
#include <string>
using namespace std;

int findIndex(char*);
int main(){
	char begin[101];
	char temp[101];
	char sum[101];
	int base,next=0;
	

	for(int i=0;i<100;i++)
		sum[i]='0';
	cin>>begin;
	while(strcmp(begin,"0")!=0)
	{
		int digit_length,zero_length,i,j=0;
		digit_length=strlen(begin);
		zero_length=100-digit_length;
		for(i=0;i<zero_length;i++)
			temp[i]='0';
		for(i=zero_length;i<100&&j<digit_length;i++,j++)
			temp[i]=begin[j];
		for(i=99;i>=0;i--){
			base=sum[i]+temp[i]-48*2;
			if(base<10)
				sum[i]=base+48;
			if(base>=10){
				sum[i]=base%10+48;
				next=base/10;
				while(next){
					int tempI=i-1;
					base=next+sum[tempI]-48;
					sum[tempI]=base%10+48;
					next=base/10;
					tempI--;
				}
			}
		}
		cin>>begin;
	}
	if(sum[99]=='0'){
		cout<<'0'<<endl;
	
		return 0;
	}
	int i=findIndex(sum);
	for(;i<100;i++)
		cout<<sum[i];
	cout<<endl;

	return 0;
}

int findIndex(char *sum){
	int i;
	for(i=0;i<100;){
		if(sum[i]=='0')
			i++;
		else return i;
	}
}