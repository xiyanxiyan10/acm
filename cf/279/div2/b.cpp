/**
 * @brief Codeforces Round #279 (Div. 2) b
 * @file b.cpp
 * @author 面码
 * @created 2014/11/27 15:29
 * @edited  2014/11/27 20:40
 * @type 
 * @note
 */
#include <cstdio>
#include <stack>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 1000010

set<int> lft_store;
set<int> rht_store;

int n;
int lft[MAXN];
int rht[MAXN];

int i;
int left, right, curr, tmp;

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
        if(left)
        lft_store.insert(left);
        if(right)
        rht_store.insert(right);
    }

    for(set<int>::iterator iter = rht_store.begin(); iter != rht_store.end(); iter++){
#ifdef DEBUG
        printf("match = %d\n", *iter);
#endif
        lft_store.erase(*iter);
    }

    /*Get queue head*/
    curr = *lft_store.begin();
    right = rht[0];

#ifdef DEBUG
    printf("curr = %d, rht = %d\n", curr, right);
#endif
    do{
        printf("%d ", curr);
        tmp = rht[curr];
        curr = right;
        right = tmp;
#ifdef DEBUG
    //printf("curr = %d, rht = %d\n", curr, right);
#endif
    }while(right);

    printf("%d\n", curr);

    return 0;
}



