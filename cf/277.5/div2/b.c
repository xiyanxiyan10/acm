/**
 * @brief Codeforces Round #277.5 (Div. 2) b
 * @file b.c
 * @author 面码
 * @created 2014/11/18 17:22
 * @edited  2014/11/18 17:22
 * @type enumeric
 * @TODO test
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
int *an;            /*an hold the sammler list*/
int *am;            /*am hold the bigger list*/
int tot;

static inline void swap(int *a, int i, int j){
        int tmp;
        tmp  = a[j];
        a[j] = a[i];
        a[i] = tmp;
}

void solve(int spos, int epos){
    int i;
    int cnt;
    if(spos == epos){
        cnt = 0;
#ifdef DEBUG
        for(i = 0; i < m; i++){
            printf("%d ", am[i]);
        }
        printf("\n");
#endif
        for(i = 0; i < n; i++)
            if(abs(am[i] - an[i]) <= 1)
                cnt++;
        tot = max(tot, cnt);
    }else{
        for(i = spos; i <= epos; i++){
                swap(am, spos, i);
                solve(spos + 1, epos);
                swap(am, spos, i);
        }
    }
}

int main()
{
    int i;
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &boys[i]);

    scanf("%d", &m);
    for(i = 0; i < m; i++)
        scanf("%d", &girls[i]);

    /*n store the smaller one*/
    if(n < m){
        an = boys;
        am = girls;
    }else{
        n = n^m;
        m = n^m;
        n = n^m;
        an = girls;
        am = boys;
    }
#ifdef DEBUG
    printf("n = %d, m = %d\n", n, m);
#endif
    
    solve(0, m - 1);

    printf("%d\n", tot);
    return 0;
}
