#include<iostream>
#include<cstring>
using namespace std;
int main()
{
 char s[110][110];
 int n,len,i,j,a[110],x,y;
  n=0;
  for(i=0;i<110;i++)
	a[i]=0;
  while(cin>>s[n])
  {
   len=strlen(s[n]);
   if(len==1&&s[n][0]=='0')  //注意：不只是s[n][0]=='0'还必须是len==1
    break;
   i=len-1;
   j=109;
   y=0;
   while(i>=0)   //求和
   {
		x=s[n][i]-'0';
		a[j]+=x+y;
		y=a[j]/10;
		a[j]=a[j]%10;
		i--;
		j--;
   }
   if(y>0)   
   {
		a[j]+=y;
		while(a[j]>9)
		{
			y=a[j]/10;
			a[j]=a[j]%10;
			j--;
			a[j]+=y;
		}
   }
	n++;
  }
  i=0;
  while(i!=109&&a[i]==0)//去除前面无用的0
	i++;
  for(j=i;j<110;j++)
   cout<<a[j];
  cout<<endl;
  //system("pause");
 return 0;
}