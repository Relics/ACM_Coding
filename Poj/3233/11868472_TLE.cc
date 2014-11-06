#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int size,k,mod;

typedef struct
{
	int a[31][31];
}Matrix;

Matrix intial;

Matrix multiply(Matrix A,Matrix B)
{
	Matrix temp;
	memset(temp.a,0,sizeof(temp.a));
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			for(int k=0;k<size;k++)
			{
				temp.a[i][j]+=A.a[i][k]*B.a[k][j];
				if(temp.a[i][j]>=mod)
					temp.a[i][j]%=mod;
			}
	return temp;
}
Matrix mi(int n)
{
	Matrix res;
	memset(res.a,0,sizeof(res.a));
	for(int i=0;i<size;i++)
		res.a[i][i]=1;
	Matrix temp;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			temp.a[i][j]=intial.a[i][j];
	while(n)
	{
		if(n&1)
			res=multiply(res,temp);
		n>>=1;
		temp=multiply(temp,temp);
	}
	return res;
}
Matrix add(Matrix A,Matrix B)
{
	Matrix temp;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
		{
			temp.a[i][j]=(A.a[i][j]+B.a[i][j]);
			if(temp.a[i][j]>=mod)
				temp.a[i][j]%=mod;
		}
	return temp;
}
Matrix cal(int k)
{
	if(k==1)
		return intial;
	if((k&1)==0)
		return add(cal(k/2),multiply(mi(k/2),cal(k/2)));
	else
		return add(cal(k-1),mi(k));
}

int main()
{
	cin>>size>>k>>mod;
	memset(intial.a,0,sizeof(intial.a));
	
	for(int i=0;i<size;i++)
	{	
		for(int j=0;j<size;j++)
		{
			scanf("%d",&intial.a[i][j]);
		}
	}
	Matrix ans;
	ans=cal(k);
	for(int i=0;i<size;i++)
	{
		int j;
		for(j=0;j<size-1;j++)
		{
			if(ans.a[i][j]>=mod)
				ans.a[i][j]%=mod;
			printf("%d ",ans.a[i][j]);
		}
		if(ans.a[i][j]>=mod)
			ans.a[i][j]%=mod;
		printf("%d\n",ans.a[i][j]);
	}
	//system("pause");
	return 0;
}
