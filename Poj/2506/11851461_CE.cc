#include <iostream>  
#incldue <cstdio>
#include <algorithm>  
using namespace std;  
struct numtype {  
       int len,a[1000];  
}dp[252];  
int n;  
void add(numtype a, numtype b, numtype &c) {  
     int i,len=max(a.len,b.len);  
     for (i=1;i<=len;i++)  
         c.a[i]=a.a[i]+b.a[i];  
     for (i=1;i<=len;i++)  
         if (c.a[i]>9) {  
                       c.a[i]-=10;  
                       c.a[i+1]++;  
         }  
     if (c.a[len+1]!=0) c.len=len+1;  
     else c.len=len;  
}  
void cheng2(numtype &x) {  
     int i;  
     for (i=1;i<=x.len;i++)  
         x.a[i]*=2;  
     for (i=1;i<=x.len;i++)  
         if (x.a[i]>9) {  
                       x.a[i]-=10;  
                       x.a[i+1]++;  
         }  
     if (x.a[x.len+1]!=0) x.len++;  
}  
int main() {  
    int i;  
    while (cin >> n) {  
          memset(dp,0,sizeof(dp));  
          dp[0].len=1;  
          dp[0].a[1]=1;  
          dp[1].len=1;  
          dp[1].a[1]=1;  
          for (i=2;i<=n;i++) {  
                   cheng2(dp[i-2]);  
                   add(dp[i-2],dp[i-1],dp[i]);  
          }  
          for (i=dp[n].len;i>=1;i--) cout << dp[n].a[i];  
          cout << endl;  
    }  
    //system("pause");  
    return 0;  
}   