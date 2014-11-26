/**
 * @brief Codeforces Round #279 (Div. 2) a
 * @file a.cpp
 * @author 面码
 * @created 2014/11/26 17:05
 * @edited  2014/11/26 17:05
 * @type 
 *
 */
#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

typedef stack<int> bbq;

#define MAXT 3

bbq a[MAXT + 1];
int type;
int n;
int cnt;

int main(void){
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
            scanf("%d", &type);
            a[type].push(i);
    }
    cnt = a[1].size();
    cnt = min(cnt, a[2].size());
    cnt = min(cnt, a[3].size());
    
    printf("%d\n", cnt);

    while( !a[1].empty() && !a[2].empty() && !a[3].empty()){
            printf("%d %d %d\n", a[1].top(), a[2].top(), a[3].top());
            a[1].pop();
            a[2].pop();
            a[3].pop();
    }
    return 0;
}



