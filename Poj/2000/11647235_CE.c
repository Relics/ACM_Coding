#include<stdio.h>
int a[10001];
int main()
{
int day=1,n,coin=0,j;
a[0]=0;
while(++coin)
for(j=0;j<coin;j++){
a[day]=a[day-1]+coin;
day++;
if(day>10000)goto a;
}
a:
while(scanf_s("%d",&n),n!=0)
printf("%d  %d",n,a[n]);

return 0;
 
}