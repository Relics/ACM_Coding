#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int max_tem=n/2;
    int min_tem=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=max_tem;++j){
            cout<<"*";
        }
        for(int j=1;j<=min_tem;++j){
            cout<<"D";
        }
        for(int j=1;j<=max_tem;++j){
            cout<<"*";
        }
        max_tem--;
        min_tem+=2;
        cout<<endl;
        if(max_tem<0)
            break;

    }
    max_tem=1;
    min_tem-=4;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=max_tem;++j){
            cout<<"*";
        }
        for(int j=1;j<=min_tem;++j){
            cout<<"D";
        }
        for(int j=1;j<=max_tem;++j){
            cout<<"*";
        }
        max_tem++;
        min_tem-=2;
        cout<<endl;
        if(min_tem<0)
            break;

    }
}