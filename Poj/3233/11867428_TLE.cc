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
	int a[30][30];
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
				temp.a[i][j]+=(A.a[i][k]*B.a[k][j])%mod;
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
			temp.a[i][j]=(A.a[i][j]+B.a[i][j])%mod;
	return temp;
}

Matrix cal(int k)
{
	Matrix temp;
	memset(temp.a,0,sizeof(temp.a));
	for(int i=1;i<=k;i++)
	{
		temp=add(temp,mi(i));
	}
	return temp;
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
		for(int j=0;j<size;j++)
		{
			printf("%d ",ans.a[i][j]%mod);
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}
