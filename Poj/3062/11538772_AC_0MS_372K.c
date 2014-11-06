#include <stdio.h>

int main(){
	char a[100];
	while(gets(a)!=NULL)
		printf("%s\n",a);
	return 0;
}