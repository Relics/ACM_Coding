#include <stdio.h>
#include <string.h>

int main(){
	char n1[11]="- -- -----";
	char n2[11]="|   ||| ||";
	char n3[11]="|||||  |||";
	char n4[11]="  ----- --";
	char n5[11]="| |   | | ";
	char n6[11]="|| |||||||";
	char n7[11]="- -- -- --";
	int size;
	int digit;
	int i,j,k,length;
	char number[10];
	while(1){
		scanf("%d%s",&size,number);
		if(size==0)break;
		length=strlen(number);
		for(i=0;i<length;i++){
			printf(" ");
			digit=number[i]-'0';
			for(j=0;j<size;j++){
				printf("%c",n1[digit]);
			}
			printf("  ");
		}
		printf("\n");

		for(i=0;i<size;i++){
			for(j=0;j<length;j++){
				digit=number[j]-'0';
				printf("%c",n2[digit]);
				for(k=0;k<size;k++){
					printf(" ");
				}
				printf("%c",n3[digit]);
				printf(" ");
			}
			printf("\n");
		}
		
		for(i=0;i<length;i++){
			digit=number[i]-'0';
			printf(" ");
			for(j=0;j<size;j++){
				printf("%c",n4[digit]);
			}
			printf("  ");
		}
		printf("\n");
		
		for(i=0;i<size;i++){
			for(j=0;j<length;j++){
				digit=number[j]-'0';
				printf("%c",n5[digit]);
				for(k=0;k<size;k++){
					printf(" ");
				}
				printf("%c",n6[digit]);
				printf(" ");
			}
			printf("\n");
		}

		for(i=0;i<length;i++){
			digit=number[i]-'0';
			printf(" ");
			for(j=0;j<size;j++){
				printf("%c",n7[digit]);
			}
			printf("  ");
		}
		printf("\n\n");
	}
	return 0;
}