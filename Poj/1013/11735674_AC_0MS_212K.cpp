#include <iostream>
#include <cstring>
using namespace std;

char leftstr[4][20];
char rightstr[4][20];
char state[4][10];

bool is_light(char x)
{
	for(int i=1;i<=3;i++)
	{
		switch(state[i][0])
		{
		case 'e':
			{
				if(strchr(leftstr[i],x)!=NULL||strchr(rightstr[i],x)!=NULL)
					return false;
				break;
			}
		case 'u':
			{
				if(strchr(rightstr[i],x)==NULL)
					return false;
				break;
			}
		case 'd':
			{
				if(strchr(leftstr[i],x)==NULL)
					return false;
				break;
			}
		}
	}
	return true;
}

bool is_heavy(char x)
{
	for(int i=1;i<=3;i++)
	{
		switch(state[i][0])
		{
		case 'e':
			{
				if(strchr(leftstr[i],x)!=NULL||strchr(rightstr[i],x)!=NULL)
					return false;
				break;
			}
		case 'd':
			{
				if(strchr(rightstr[i],x)==NULL)
					return false;
				break;
			}
		case 'u':
			{
				if(strchr(leftstr[i],x)==NULL)
					return false;
				break;
			}
		}
	}
	return true;
}
void ans()
{
	char x;
	for(x='A';x<='L';x++)
	{
		if(is_light(x))
		{
			cout<<x<<" is the counterfeit coin and it is light."<<endl;
			break;
		}
		if(is_heavy(x))
		{
			cout<<x<<" is the counterfeit coin and it is heavy."<<endl;
			break;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		for(int i=1;i<=3;i++)
		{
			cin>>leftstr[i]>>rightstr[i]>>state[i];
		}
		ans();
	}
	return 0;
}