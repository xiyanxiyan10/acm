/**
 * @brief Codeforces Round #277.5 (Div. 2) c
 * @file a.c
 * @author 面码
 * @created 2014/11/18 16:37
 * @edited  2014/11/18 16:37
 * @type sort
 *
 */
#include <stdio.h>

#define MAXN 3010

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))

int n;          
int vec[MAXN]; 
int ans[MAXN][2];
int tot;

static inline void swap(int *a, int i, int j){
        int tmp;
        if(a[i] == a[j])
            return ;

        /*record waap*/
        ans[tot][0] = i;
        ans[tot][1] = j;
        tot++;

        tmp  = a[j];
        a[j] = a[i];
        a[i] = tmp;
#ifdef DEBUG
    for(i = 0; i < n; i++)
        printf("%d%c", vec[i], i < n - 1? ' ': '\n');
#endif
}

void select_sort(int *a, int n){
    int i, j, maxval, maxpos;
    for(i = n - 1; i >= 1 ; i--){
        maxval = a[i];
        maxpos = i;
        for(j = 0; j < i; j++)
            if(a[j] > maxval){
                maxval = a[j];
                maxpos = j;
            }
        swap(a, maxpos, i);
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
       scanf("%d", &vec[i]);

    tot = 0;

    /*select sort process*/
    select_sort(vec, n);
    
    printf("%d\n", tot);
    for(i = 0; i < tot; i++)
        printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
}
