/**
 * @brief Codeforces Round #279 (Div. 2) b
 * @file b.cpp
 * @author 面码
 * @created 2014/11/27 15:29
 * @edited  2014/11/27 15:29
 * @type 
 * @note
 *      1. build 0 <- ? -> a <- ? -> b ->0
 *      2. get ans
 *
 * @TODO wait to test
 */
#include <cstdio>
#include <stack>
#include <cstring>
#include <set>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 1000010

int n;
/*stand from left to right*/
set <int> store;
int ans[MAXN];
int cnt;

int lft[MAXN];
int rht[MAXN];

int i;
int left, right;

int main(void){
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d", &n);
    for(i = 0; i < n ; i++){
        scanf("%d%d", &left, &right);
        lft[right] = left;
        rht[left]  = right;
        store.insert(right);
    }

    /*2 need spicial solve*/
    if(n == 2){
        printf("%d %d\n", lft[0], rht[0]);
        return 0;
    }

    /*get header*/
    cnt = 0;
    right = rht[0];    
    
    while(right){
        ans[cnt++] = right;
        right = rht[right];
    }
    
    
    return 0;
}



