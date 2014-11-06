#include <stdio.h>   
  
int main()  
{  
    int day, mony;  
    int i, j;  
      
    while (scanf("%d", &day), day) {  
          mony = 0;  
          for (i = j = 1; i <= day; j++, i+=j)  
              mony += j*j;  
          mony += (day-i+j)*j;  
          printf("%d %d\n", day, mony);  
    }  
    return 0;  
}  
