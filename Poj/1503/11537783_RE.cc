#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char begin[101];
	char temp[101];
	char sum[101];
	int base,next=0;
	int digit_length,zero_length,i,j=0;
	int tempI;
	
	begin[100]=0;
	temp[100]=0;
	sum[100]=0;
	for(i=0;i<100;i++)
		sum[i]='0';
	cin>>begin;
	while(strcmp(begin,"0")!=0)
	{
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
					tempI=i-1;
					base=next+sum[tempI]-48;
					sum[tempI]=base%10+48;
					next=base/10;
					tempI--;
				}
			}
		}
		j=0;
		cin>>begin;
	}
	i=0;
	while(i<100&&sum[i]=='0')
		i++;
	if(i==100){
		cout<<'0'<<endl;
	}else{
		for(j=i;j<100;j++){
			cout<<sum[j];
		}
		cout<<endl;
	}
	return 0;
}
