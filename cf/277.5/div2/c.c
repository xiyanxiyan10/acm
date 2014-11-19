/**
 * @brief Codeforces Round #277.5 (Div. 2) c
 * @file c.c
 * @author 面码
 * @created 2014/11/18 17:22
 * @edited  2014/11/18 17:22
 * @type greedy
 */
#include <stdio.h>
#include <string.h>

#define MAXN 110    /*len*/

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))

char buf[MAXN];

int m, s;
int min_val;

int main()
{
    int i, j, len, base, cnt;
    char tmp;
    char buf[MAXN];
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d", &m, &s);

    for(base = 9, len = 0; s && len <= m && base > 0; base--){
        if(s >= base){
            cnt  = s/base;
            s    = s%base;
        }
        while(cnt--)
            buf[len++] = i + '0';
    }
    if(len > m){
        printf("-1 -1\n");
        return 0;
    }else{
        while(len <= m)
            buf[len++] = '0';
    }

    printf("%s ", buf);
    i = 0;
    j = len -1;

    while(i < j){
        tmp    = buf[i];
        buf[i] = buf[j];
        buf[j] = tmp;

        i++;
        j--;
    }
    
    printf("%s\n", buf);
    return 0;
}
