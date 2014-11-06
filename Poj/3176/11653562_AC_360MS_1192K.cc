#include <iostream>
using namespace std;

int main(){
	int N;
	int i,j;
	while(cin>>N)
	{
		int **way=new int*[N+1];
		for(i=0;i<N+1;i++)
		{
			way[i]=new int[i+1];
			for(j=0;j<=i+1;j++)  
                way[i][j]=0; 
			if(i!=0)
				for(j=0;j<i;j++)
					cin>>way[i][j];
		}
		int **Maxway=new int*[N+1];
		for(i=0;i<N+1;i++)
		{
			Maxway[i]=new int[i+1];
			for(j=0;j<i;j++)
				Maxway[i][j]=way[i][j];
		}
		
		for(i=N;i>1;i--)
		{
			for(j=0;j<i;j++)
			{
				if(Maxway[i][j]>Maxway[i][j+1])
					Maxway[i-1][j]=Maxway[i][j]+way[i-1][j];
				else
					Maxway[i-1][j]=Maxway[i][j+1]+way[i-1][j];
			}
		}
		cout<<Maxway[1][0]<<endl;
	}	

	return 0;
}