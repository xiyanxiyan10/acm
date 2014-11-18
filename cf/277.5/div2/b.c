/**
 * @brief Codeforces Round #277.5 (Div. 2) b
 * @file b.c
 * @author 面码
 * @created 2014/11/18 17:22
 * @edited  2014/11/18 17:22
 * @type greedy
 *
 */
#include <stdio.h>

#define MAXN 110

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))

int n, m;
int girls[MAXN];
int boys[MAXN];
int tot;

int main()
{
    int i, val;
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &val);
        ++boys[val];
    }

    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d", &val);
        ++girls[val];
    }

    /*greedy here， we must see the problem from boys or girls, this is very important*/
    tot = 0;
    for(i = 1; i <= 100; i++){
        val = min(boys[i], girls[i - 1]);
        tot             += val;
        boys[i]         -= val;
        girls[i - 1]    -= val;

        val = min(boys[i], girls[i]);
        tot             += val;
        boys[i]         -= val;
        girls[i]        -= val;
    
        val = min(boys[i], girls[i + 1]);
        tot             += val;
        boys[i]         -= val;
        girls[i + 1]    -= val;
    }

    printf("%d\n", tot);
    return 0;
}
