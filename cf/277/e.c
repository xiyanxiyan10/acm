/**
 * @brief Codeforces Round #277 (Div. 2) e
 * @file e.c
 * @author 面码
 * @created 2014/11/14 13:39
 * @edited  2014/11/14 13:39
 * @type LIS
 *
 */
#include <stdio.h>
#include <string.h>

#define MAXN 100050

#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#define MIN(a, b)  ((a) > (b) ? (b) : (a)) 
#define ABS(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

int len[MAXN];    /*record the max len pos i in*/
int dif[MAXN];    /*set if belong to differetn len*/
int table[MAXN];  /*store input*/
int tmp[MAXN];    /*used for LIS*/

int bsearch(int *a, int x, int y, int v)
{
    int m;
    while(x < y){
            m = x + ((y - x) >> 1);
            if(a[m] >= v)
                    y = m;
            else
                    x = m + 1;
    } 
    return x;
}


int main(void){
    int i, n;
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d", &n);
    for(i = 0; i< n; i++)
            scanf("%d", &table[i]);
    for(i = 1; i < (1<< n); i++){
        
    }
    return 0;
}

