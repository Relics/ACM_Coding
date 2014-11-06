#include <iostream>
using namespace std;

int round=0;
int matrix[5][6];
int press[5][6];
int minround=-1;

bool could_all_b()//将matrix全变为1
{
	int r,c;
	round=0;
	for(r=1;r<=3;r++)
		for(c=1;c<=4;c++)
		{
			press[r+1][c]=(matrix[r][c]+press[r][c]+press[r-1][c]+press[r][c-1]+press[r][c+1]+1)%2;
		}
	for(c=1;c<=4;c++)
		if((press[4][c-1]+press[4][c]+press[4][c+1]+press[3][c]+1)%2!=matrix[4][c])
			return false;
	for(r=1;r<=4;r++)
		for(c=1;c<=4;c++)
		{
			if(press[r][c]==1)
				round++;
		}
	return true;
}

bool could_all_w()//将matrix全变为0
{
	int r,c;
	round=0;
	for(r=1;r<=3;r++)
		for(c=1;c<=4;c++)
		{
			press[r+1][c]=(matrix[r][c]+press[r][c]+press[r-1][c]+press[r][c-1]+press[r][c+1])%2;
		}
	for(c=1;c<=4;c++)
		if((press[4][c-1]+press[4][c]+press[4][c+1]+press[3][c])%2!=matrix[4][c])
			return false;
	for(r=1;r<=4;r++)
		for(c=1;c<=4;c++)
		{
			if(press[r][c]==1)
				round++;
		}
	return true;
}
int enumerate()
{
	int i;
	
	//Intialize the press
	memset(press,0,sizeof(press));
	int c;
	while(press[1][5]!=1)
	{
		c=1;
		while(press[1][c]>1)
		{
			press[1][c]=0;
			c++;
			press[1][c]++;
		}
		if(could_all_b())
		{
			if(minround<0)
				minround=round;
			else
				minround=min(minround,round);
		}
		press[1][1]++;
	}

	//Intialize the press
	memset(press,0,sizeof(press));
	while(press[1][5]!=1)
	{
		c=1;
		while(press[1][c]>1)
		{
			press[1][c]=0;
			c++;
			press[1][c]++;
		}
		if(could_all_w())
		{	
			if(minround<0)
				minround=round;
			else
				minround=min(round,minround);
		}
		press[1][1]++;
	}
	return minround;
}

int main()
{
	char puzzle[5][5];
	int i,j;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			cin>>puzzle[i][j];
			if(puzzle[i][j]=='b')
				matrix[i][j]=1;
			if(puzzle[i][j]=='w')
				matrix[i][j]=0;
		}
	}
	if(enumerate()<0)
	{
		cout<<"Impossible"<<endl;
	}
	else
		cout<<minround<<endl;
	//system("pause");
	return 0;
}