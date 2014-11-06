#include <iostream>
using namespace std;

int c,r;
char puzzle[21][21];
int f(int x,int y)
{
	if(x<0||x>=r||y<0||y>=c)
		return 0;
	if(puzzle[x][y]=='#')
		return 0;
	else{
		puzzle[x][y]='#';
		return 1+f(x-1,y)+f(x+1,y)+f(x,y-1)+f(x,y+1);
	}
}

int main()
{
	for(;;)
	{
		int i,j;
		cin>>c>>r;
		if(c==0&&r==0)
			break;
		for(i=0;i<r;i++)
			cin>>puzzle[i];
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				if(puzzle[i][j]=='@')
					cout<<f(i,j)<<endl;
	}
	return 0;
}