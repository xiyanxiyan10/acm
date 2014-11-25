/**
 * @brief Codeforces Round #278 (Div. 2) d
 * @file d.c
 * @author 面码
 * @created 2014/11/25 15:49
 * @edited  2014/11/25 15:49
 * @type dp
 *
 */
#include <stdio.h>
#include <string.h>

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 100010
#define MAXS 1000000010
#define MAXl 100010

int in[MAXN];
int dp[MAXN];
int n, s, l;

int main()
{
    int i, j, k, min_cnt, max_num, min_num;
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &s, &l);
    for(i = 1; i <= n; i++)
        scanf("%d", &in[i]);

    for(i = 1; i <= n; i++){
        if(i < l){
            dp[i] = -1;                 /* no answer*/     
            continue;
        }
        min_cnt = MAXN;
        for(j = 0; j + l <= i; j++){    /*use record*/
            if(dp[j] < 0)
                    continue;
            max_num = -1;
            min_num = MAXS;
            for(k = j + 1; k <= i; k++){
                    max_num = max(max_num, in[k]);
                    min_num = min(min_num, in[k]);
            }
            if(max_num - min_num > s)
                continue;
            min_cnt = min(min_cnt, dp[j] + 1);
        }  
        dp[i] = min_cnt == MAXN ? -1 : min_cnt;
    }
    printf("%d\n", dp[n] < 0 ? -1 : dp[n]);
    return 0;
}
