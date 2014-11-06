#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef struct
{
	int a[2][2];
}Matrix;

Matrix intial_change;
Matrix intial_fixed;
Matrix ans;

Matrix multiply(Matrix A,Matrix B)
{
	int i,j,k;
	Matrix temp;
	memset(temp.a,0,sizeof(temp.a));
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			for(k=0;k<2;k++)
			{
				temp.a[i][j]+=A.a[i][k]%10000*B.a[k][j]%10000;
				temp.a[i][j]%=10000;
			}
	return temp;
}

Matrix mi(int n)
{
	while(n)
	{
		if(n&1)
			ans=multiply(ans,intial_change);
		n>>=1;
		intial_change=multiply(intial_change,intial_change);
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		ans.a[0][0]=1;
		ans.a[0][1]=0;
		ans.a[1][0]=0;
		ans.a[1][1]=1;
		intial_change.a[0][0]=1;
		intial_change.a[0][1]=1;
		intial_change.a[1][0]=1;
		intial_change.a[1][1]=0;
		intial_fixed.a[0][0]=1;
		intial_fixed.a[0][1]=1;
		intial_fixed.a[1][0]=1;
		intial_fixed.a[1][1]=0;
		if(n==0)
		{
			printf("0\n");
			scanf("%d",&n);
			continue;
		}
		if(n==1||n==2)
		{
			printf("1\n");
			scanf("%d",&n);
			continue;
		}
		int k=n-2;
		ans=multiply(intial_fixed,mi(k));
		printf("%d\n",ans.a[0][0]);
		scanf("%d",&n);
	}
	return 0;
}