#include <stdio.h>

int main(){
	char a[100];
	int i;
	for(i=0;i<100;i++)
	{
		gets(a);
		printf("%s\n",a);
	}
	return 0;
}