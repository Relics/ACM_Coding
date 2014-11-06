#include <stdio.h>

int main(){
	int a[10001];
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
	while(scanf("%d",&n)!=EOF&&n)
	{
		printf("%d %d\n",n,a[n]);
	}
	return 0;
}
