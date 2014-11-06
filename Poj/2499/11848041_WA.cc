#include<cstdio>
using namespace std;
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
        int i=1;
		scanf("%d%d",&a,&b);
		int l=0,r=0;
		while(a!=1||b!=1)
	   {
		  if(a==1)
		  {
			r+=b-a;
			break;
		  }
		  if(b==1)
		  {
			l+=a-b;
			break;
		  }
		  if(a>b)
		  {
			l+=a/b;
			a-=b*(a/b);
		  }
		  else
		  {
			r+=b/a;
			b-=a*(b/a);
		  }
	   }
		printf("Scenario #%d:\n",i++);
		printf("%d %d\n\n",l,r);
	}
	return 0;
}
