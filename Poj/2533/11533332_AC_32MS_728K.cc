#include <iostream>
using namespace std;
#define Maxnumber 1001
int main(){
	int N;
	int a[Maxnumber];
	int amax[Maxnumber];
	int i,j;
	int tempMax=0;
	cin>>N;
	for(i=1;i<=N;i++)
		cin>>a[i];
	amax[1]=1;
	for(i=2;i<=N;i++){
		tempMax=0;
		for(j=1;j<i;j++){
			if(a[i]>a[j]){
				if(amax[j]>tempMax){
					tempMax=amax[j];
				}
			}
		}
		amax[i]=tempMax+1;
	}
	int Max=0;
	for(i=1;i<=N;i++)
		if(Max<amax[i])
			Max=amax[i];
	cout<<Max<<endl;
	return 0;
}
