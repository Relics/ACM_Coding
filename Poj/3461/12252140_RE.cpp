#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxnum=1e5;

int next[maxnum];
int nextval[maxnum];
char s[(int)(1e6+100)];
char p[maxnum];

void get_next()
{
    next[0]=-1;
    int i=0; //主串下标
    int j=-1;//匹配串下标
    int length=strlen(p);
    while(i<length)
    {
        if(j==-1||p[i]==p[j])
        {
            ++i;//将主串下标后移一位
            ++j;//将匹配串下标后移一位
            next[i]=j;
        }
        else j=next[j];
    }
}
void kmp(int &ans)
{
    int i=0;//主串的移动下标
    int j=0;//匹配串的移动下标
    int len_s=strlen(s);//主串的长度
    int len_p=strlen(p);//匹配串的长度
    while(i<len_s&&j<len_p)
    {
        if(j==-1||s[i]==p[j])
        {
            ++i;
            ++j;
            if(j==len_p)
            {
                j=next[j];
                ++ans;
            }
        }
        else j=next[j];
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int ans=0;
        scanf("%s",s);
        scanf("%s",p);
        get_next();
        kmp(ans);
        cout<<ans;
        printf("\n");
    }
    return 0;
}
