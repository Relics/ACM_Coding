#include <stdio.h>
#include <string.h>

int main(){
	char a[255];
	int n,i,sum=0;

	while(1){
		gets(a);
		if(strcmp(a,"#")==0)break;
		n=strlen(a);
		for(i=0;i<n;i++){
			if((a[i]<='Z')&&(a[i]>='A')){
				sum+=((i+1)*(a[i]-64));
			}
		}
		printf("%d\n",sum);
		sum=0;
	}
	return 0;
}