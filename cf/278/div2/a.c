/**
 * @brief Codeforces Round #278 (Div. 2) a
 * @file a.c
 * @author 面码
 * @created 2014/11/24 16:07
 * @edited  2014/11/18 16:07
 * @type sort
 *
 */
#include <stdio.h>

#define MAXN 17777777777
#define MINNUM -8888888888
#define MAXNUM  8888888888

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))

long long int base;

int main()
{
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%I64d", &base);
    base += MINNUM;
    printf("%lld\n", curr - base);
    return 0;
}
