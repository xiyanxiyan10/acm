/**
 * @brief Codeforces Round #277.5 (Div. 2) d
 * @file d.cpp
 * @author 面码
 * @created 2014/11/22 11:23
 * @edited  2014/11/22 11:23
 * @type brute
 * @note 
 */
#include <cstdio>
#include <cstring>
#include <vector>

#define MAXN 3010   /*max note*/
#define MAXE 30010  /*max edge*/

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

using namespace std;

int ans;
int n, m;

vector<int>tree[MAXN];
int table[MAXN][MAXN];  /*flag there is a way from m to n*/

int main()
{
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int from, to;
        scanf("%d%d", &from, &to);
        tree[from].push_back(to);
        table[from][to] = 1;
    }
    ans = 0;
    for( int from = 1; from <= n; from++)
        for( int to = 1; to <= n; to++){
            if( from == to)
                continue;
            int cnt = 0;
            for(int i = 0; i < tree[from].size(); i++){
                    if(table[tree[from][i]][to])
                        cnt++;
            }
            ans += cnt >= 2? (cnt * (cnt - 1))>>1 : 0;
        }
    printf("%d\n", ans);
    return 0;
}
