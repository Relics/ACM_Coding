#include <stdio.h>

int main(){
	int i;
	double a,sum=0;

	for(i=0;i<12;i++){
		scanf("%lf",&a);
		sum+=a;
	}
	sum/=12;
	printf("$%.2f",sum);
	return 0;
}
