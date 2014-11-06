#include <stdio.h>

int main(){
	int i=1;
	int n;
	int t;
	int a[51];
	int max;
	int b;
	int average;
	while(scanf("%d",&n)!=EOF&&n){
		b=0;
		max=0;
		for(t=1;t<=n;t++)
		{
			scanf("%d",&(a[t]));
			max+=a[t];
		}
		average=max/n;
		for(t=1;t<=n;t++)
		{
			if(a[t]>average)
				b+=a[t]-average;
		}
		printf("Set #%d\n",i);
		printf("The minimum number of moves is %d.\n\n",b);
		i++;
	}
	return 0;
}
		