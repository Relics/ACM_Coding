#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	char s[100010],t[100010];
	int Currents,Currentt;
	int Lengths,Lengtht;
	scanf("%d",&T);
	while(T--)
	{
		Currents=Currentt=0;
		scanf("%s%s",s,t);
		Lengths=strlen(s);
		Lengtht=strlen(t);
		while(Currents<Lengths&&Currentt<Lengtht)
		{
			if(s[Currents]==t[Currentt])
			{
				Currents++;
				Currentt++;
			}
			else
			{
				Currentt++;
			}
			if(Currents==Lengths-1)
				break;
		}
		if(Currents==Lengths-1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}