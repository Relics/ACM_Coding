#include <iostream>
using namespace std;

int main()
{
	int a[20];;
	for(;;)
	{
		int counts=0;
		memset(a,0,sizeof(a));
		int i=1;
		for(;;i++)
		{
			scanf("%d",&a[i]);
			if(a[1]==-1)
				break;
			if(a[i]==0)
				break;
		}
		i=i-1;
		if(-1==a[1])
			break;
		for(int j=1;j<=i-1;j++)
		{
			for(int k=j+1;k<=i;k++)
			{
				if((a[k]==a[j]*2)||(a[k]*2==a[j]))
					counts++;
			}
		}
		printf("%d\n",counts);
	}
	return 0;
}