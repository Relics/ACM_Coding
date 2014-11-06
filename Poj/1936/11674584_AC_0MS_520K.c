#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	char s[100010],t[100010];
	int Currents=0,Currentt=0;
	int Lengths,Lengtht;

	while(scanf("%s%s",s,t)!=EOF)
	{
		Currents=Currentt=0;
		Lengths=strlen(s);
		Lengtht=strlen(t);
		while(Currentt<Lengtht&&Currents<Lengths)
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
		}
		if(Currents==Lengths)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}