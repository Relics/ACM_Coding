
#include<stdio.h>
#include<string.h>
char n1[11]={"- -- -----"};
char n2[11]={"|   ||| ||"};
char n3[11]={"|||||  |||"};
char n4[11]={"  ----- --"};
char n5[11]={"| |   | | "};
char n6[11]={"|| |||||||"};
char n7[11]={"- -- -- --"};
int main()
{
 int s;
 char str[20];
 int d,l,i,j,k;
 while(1)
 {
  scanf("%d%s",&s,str);
  if(s==0)
   break;
  l=strlen(str);
  for(i=0;i<l;i++)
  {
   d=str[i]-'0';
  printf(" ");
  for(j=0;j<s;j++)
   printf("%c",n1[d]);
  printf("  ");
  }
  printf("\n");
  for(i=0;i<s;i++)
  {
   for(j=0;j<l;j++)
   {
    d=str[j]-'0';
    printf("%c",n2[d]);
    for(k=0;k<s;k++)
     printf(" ");
    printf("%c ",n3[d]);
   }
   printf("\n");
  }
  for(i=0;i<l;i++)
  {
   printf(" ");
   d=str[i]-'0';
   for(j=0;j<s;j++)
    printf("%c",n4[d]);
   printf("  ");
  }
  printf("\n");
        for(i=0;i<s;i++)
  {
   for(j=0;j<l;j++)
   {
    d=str[j]-'0';
    printf("%c",n5[d]);
    for(k=0;k<s;k++)
     printf(" ");
    printf("%c ",n6[d]);
   }
   printf("\n");
  }
  for(i=0;i<l;i++)
  {
   printf(" ");
   d=str[i]-'0';
   for(j=0;j<s;j++)
    printf("%c",n7[d]);
   printf("  ");
  }
  printf("\n");
  printf("\n");
 }
 return 0;
}
 