#include <iostream>
#include <algorithm>
using namespace std;

int row,column;
int point[101][101];
int dp[101][101]; 
int maxlength=0;

int rundp(int i,int j)
{
    int dpmax=1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i>1)
        if(point[i][j]>point[i-1][j])
        {
            dpmax=1+rundp(i-1,j);
        } 
    if(i<row)
        if(point[i][j]>point[i+1][j])
        {
            dpmax=max(dpmax,1+rundp(i+1,j));
        }
    if(j>1)
        if(point[i][j]>point[i][j-1])
        {
            dpmax=max(dpmax,1+rundp(i,j-1));
        }
    if(j<column)
        if(point[i][j]>point[i][j+1])
        {
            dpmax=max(dpmax,1+rundp(i,j+1));
        }    
    return dpmax;
} 

int main()
{
    int i,j;
    cin>>row>>column;
    for(i=1;i<=row;i++)
        for(j=1;j<=column;j++)
        {
            cin>>point[i][j];
            //dp[i][j]=-1;
        }
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=row;i++)
        for(j=1;j<=column;j++)
            dp[i][j]=rundp(i,j);
    for(i=1;i<=row;i++)
        for(j=1;j<=column;j++)
            maxlength=max(maxlength,dp[i][j]);
    cout<<maxlength<<endl;
    return 0;
} 
