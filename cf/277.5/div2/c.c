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

char buf_max[MAXN];
char buf_min[MAXN];

int m, s, sum;
int min_val;

int main()
{
    int i, j, base, cnt;
    char tmp;
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d", &m, &s);
    if( 0 == s){
        if(1 == m){
            printf("0 0\n");
            return 0;
        }else{
            printf("-1 -1\n");
            return 0;
        }
    }else{
        if(9*m < s){
            printf("-1 -1\n");
            return 0;
        }
    }

    /*here must have an answer*/

    /*max num*/
    sum = s;
    for(base = 9, i = 0; sum > 0 && i <= m && base > 0; base--){
        if(sum >= base){
            cnt    = sum/base;
            sum    = sum%base;
        }else
            continue;

        while(cnt--)
            buf_max[i++] = base + '0';
    }

    while(i < m)
        buf_max[i++] = '0';

    /*min num*/
    sum = s;
    for(base = 9, i = m - 1; sum > 0 && i >= 0 && base > 0; base--){
        if(sum >= base){
            cnt  = sum/base;
            sum  = sum%base;
        }else
            continue;

        while(cnt--)
            buf_min[i--] = base + '0';
    }
    if(0 == buf_min[0]){
            buf_min[0] = '1';
            buf_min[i + 1]--;
    }
    while(i > 0)
            buf_min[i++] = '0';
    
    /*output answer*/
    printf("%s %s\n", buf_min, buf_max);
    return 0;
}
