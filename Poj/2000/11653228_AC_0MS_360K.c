#include <stdio.h>

int main(){
	int a[10100];
	int day;
	int count=1;
	int i;
	int n;
	a[0]=0;
	for(day=1;day<=10000;)
	{
		for(i=0;i<count;i++)
			a[day++]=a[day-1]+count;
		count++;
	}
	scanf("%d",&n);
	while(n!=0)
	{
		printf("%d %d\n",n,a[n]);
		scanf("%d",&n);
	}
	return 0;
}
