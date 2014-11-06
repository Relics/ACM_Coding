#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#define MAX 33
using namespace std;

int size,k,mod;

typedef struct
{
	int a[MAX][MAX];
}Matrix;

Matrix intial;

Matrix multiply(Matrix A,Matrix B)
{
	Matrix temp;
	memset(temp.a,0,sizeof(temp.a));
	int i,j,k;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			for(k=0;k<size;k++)
			{
				temp.a[i][j]+=A.a[i][k]*B.a[k][j];
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
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			temp.a[i][j]=A.a[i][j]+B.a[i][j];
			temp.a[i][j]%=mod;
		}
	}
	return temp;
}
Matrix cal(int k)
{
	if(k==1)
		return intial;
	Matrix temp1=cal(k/2);
	Matrix temp2=mi(k/2);
	if((k&1)==0)
		return add(temp1,multiply(temp2,temp1));
	else
		return add(intial,add(multiply(intial,temp1),multiply(temp2,temp1)));
}

int main()
{
	cin>>size>>k>>mod;
	memset(intial.a,0,sizeof(intial.a));
	int i,j;
	for(i=0;i<size;i++)
	{	
		for(j=0;j<size;j++)
		{
			scanf("%d",&intial.a[i][j]);
		}
	}
	Matrix ans;
	ans=cal(k);
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			printf("%d ",ans.a[i][j]);
		}
		printf("%d\n",ans.a[i][j]);
	}
	//system("pause");
	return 0;
}
