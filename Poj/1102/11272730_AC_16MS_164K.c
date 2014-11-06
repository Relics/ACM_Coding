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
	int size,n,i,j,k,ndigit;
	char number[10];

	while(1){
		scanf("%d%s",&size,number);
		if(size==0)break;
		n=strlen(number);
		for(i=0;i<n;i++){
			printf(" ");
			ndigit=number[i]-'0';
			for(j=0;j<size;j++){
				printf("%c",n1[ndigit]);
			}
			printf("  ");
		}
		printf("\n");
		
		for(i=0;i<size;i++){
			for(j=0;j<n;j++){
				ndigit=number[j]-'0';
				printf("%c",n2[ndigit]);
				for(k=0;k<size;k++){
					printf(" ");
				}
				printf("%c",n3[ndigit]);
				printf(" ");
			}
			printf("\n");
		}

		for(i=0;i<n;i++){
			ndigit=number[i]-'0';
			printf(" ");
			for(j=0;j<size;j++){
				printf("%c",n4[ndigit]);
			}
			printf("  ");
		}
		printf("\n");

		for (i=0;i<size;i++){
			for(j=0;j<n;j++){
				ndigit=number[j]-'0';
				printf("%c",n5[ndigit]);
				for(k=0;k<size;k++){
					printf(" ");
				}
				printf("%c",n6[ndigit]);
				printf(" ");
			}
			printf("\n");
		}

		for(i=0;i<n;i++){
			ndigit=number[i]-'0';
			printf(" ");
			for(j=0;j<size;j++){
				printf("%c",n7[ndigit]);
			}
			printf("  ");
		}
		printf("\n\n");
	}
	return 0;
}