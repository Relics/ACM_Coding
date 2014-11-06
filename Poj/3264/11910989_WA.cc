#include <stdio.h>  
#include <string.h>  
#define MIN 0  
#define MAX 1000001  
#define LEN 50000  
typedef struct segment  
{  
    int l;  
    int r;  
    int min;  
    int max;  
}segment;  
  
segment s[LEN*3];  
int min, max;  
  
/* 
 * S_init 
 *      鏋勯€犵嚎娈垫爲 
 *      [l, r]  - 鑺傜偣鍖洪棿 
 *      index   - 瀛樺偍浣嶇疆 
 */  
void S_init(int l, int r, int index)  
{  
    int mid;  
    s[index].l = l;  
    s[index].r = r;  
    s[index].min = MAX;  
    s[index].max = MIN;  
    if (l == r)  
        return;  
    mid = (l + r) >> 1;  
    S_init(l, mid, index*2);    // 宸﹀瀛? 
    S_init(mid+1, r, index*2+1);// 鍙冲瀛? 
}  
/* 
 * S_insert 
 *      灏嗘暟鎹彃鍏ュ埌绾挎鏍?
 *      p   - 鏁版嵁鐨勪綅缃?
 *      d   - 鏁版嵁 
 */  
void S_insert(int l, int r, int index, int p, int d)  
{  
    int mid = 0;  
    if (l <= p && p <= r) // p鍦ㄧ嚎娈典笂  
    {  
        if (s[index].min > d)  
            s[index].min = d;  
        if (s[index].max < d)  
            s[index].max = d;  
    }  
  
    if (l == r)return;  
  
    mid = (l + r) >> 1;  
    if (mid >= p)    // 宸﹀瀛? 
        S_insert(l, mid, index*2, p, d);  
    else  
        S_insert(mid+1, r, index*2+1, p, d);  
}  
  
void S_query(int l, int r, int index, int a, int b)  
{  
    int mid = 0;  
    if (l == a && r == b)   // p鍦ㄧ嚎娈典笂  
    {  
        if (min > s[index].min)  
            min = s[index].min;  
        if (max < s[index].max)  
            max = s[index].max;  
        return;  
    }  
    if (l == r) return;  
    mid = (l + r) >> 1;  
    if (mid >= b)  
        S_query(l, mid, index*2, a, b);  
    else if (mid < a)  
        S_query(mid+1, r, index*2+1, a, b);  
    else    // 鍒嗗紑  
    {  
        S_query(l, mid, index*2, a, mid);  
        S_query(mid+1, r, index*2+1, mid+1, b);  
    }  
}  
int main()  
{  
    int n, m;  
    int d;  
    int i;  
    int a, b;  
    scanf("%d %d", &n, &m);  
    S_init(1, n, 1);  
    for (i=0; i<n; i++)  
    {  
        scanf("%d", &d);  
        S_insert(1, n, 1, i+1, d);  
    }  
    while (m--)  
    {  
        scanf("%d %d", &a, &b);  
        min = MAX;  
        max = MIN;  
        S_query(1, n, 1, a, b);  
        printf("%d/n", max - min);  
    }  
    return 0;  
}  