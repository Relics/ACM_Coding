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
    int j=-1;//匹配串下标(其实是自身)
    int length=strlen(p);
    while(i<length)
    {
        if(j==-1||p[i]==p[j])
        {
            ++i;//将主串下标后移一位
            ++j;//将匹配串下标后移一位
            next[i]=j;//next[i]记录的是上一次两个字符相等时，下一次比较不成功应该比较的字符位置
            //包含next[len_p]哦！
        }
        else j=next[j];
    }
}

void get_nextval()
{
    nextval[0]=-1;
    int i=0;//主串下标
    int j=-1;//匹配串下标(其实是自身)
    int length=strlen(p);
    while(i<length)
    {
        if(j==-1||p[i]==p[j])
        {
            ++i;
            ++j;
            if(p[i]!=p[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else j=nextval[j];
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
                j=next[j]; //非常神奇的地方！由于p[len_p-1]和s[i-1]比较的字符相同，而p[len_p]和s[i]比较的字符一定不同，因而要移到这个位置
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
        scanf("%s",p);
        scanf("%s",s);
        get_next();
        kmp(ans);
        cout<<ans;
        printf("\n");
    }
    return 0;
}
