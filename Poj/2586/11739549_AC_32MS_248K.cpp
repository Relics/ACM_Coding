#include <iostream>  
#include <cstdio>  
  
using namespace std;  
  
int main()  
{  
    //freopen("temp.txt", "r", stdin);  
    double s,d;  
    int surplus;  
    bool flag;  
    while (cin >> s >> d) {  
                flag = false;  
        if (s >= 4*d)   
            flag = true;  
  
        if (s >= 0 && s < 0.25*d) {  
            surplus = 10*s - 2*d;  
            if (surplus < 0)  
                flag = true;  
        } else if (s < 2.0/3*d) {  
            surplus = 8*s - 4*d;  
            if (surplus < 0)  
                flag = true;  
        } else if (s < 3.0/2*d) {  
            surplus = 6*s - 6*d;  
            if (surplus < 0)  
                flag = true;  
        } else if (s < 4*d) {  
            surplus = 3*s - 9*d;  
            if (surplus < 0)  
                flag = true;  
        }  
  
        if (flag)  
            cout << "Deficit" << endl;  
        else   
            cout << surplus << endl;  
    }  
    return 0;  
}  