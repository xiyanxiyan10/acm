/**
 * @brief Codeforces Round #277.5 (Div. 2) d
 * @file d.cpp
 * @author 面码
 * @created 2014/11/19 18:32
 * @edited  2014/11/19 18:32
 * @type brute
 * #TODO 题意理解错误，更改部分待完成
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

int main()
{
    int i, j, k, cnt;
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d%d", &j, &k);
        tree[j].push_back(k);
    }
    ans = 0;
    for( i = 1; i <= n; i++)
        for( j = 1; j <= n; j++){
            if( i == j)
                continue;
            cnt = 0;
            for(k = 0; k < tree[i].size(); k++){
                    if(tree[i][k] == j)
                        cnt++;
            }
            ans += cnt ? (cnt * (cnt - 1))>>1 : 0;
        }
    printf("%d\n", ans);
    return 0;
}
