/**
 * @brief Codeforces Round #278 (Div. 2) d
 * @file d.c
 * @author 面码
 * @created 2014/11/26 10:07
 * @edited  2014/11/26 10:07
 * @type dp 
 * @note
 *      自己的TL了，看了别人代码写的
 *      该代码主要是在dp的基础上使用stl来提速
 *      dp需辅助提速,但内存又不能爆掉是该题目的卡点 = =
 */
#include <cstdio>
#include <set>
#include <utility>
#include <string.h>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 100010
#define MAXS 1000000010
#define MAXl 100010

typedef pair<int, int> bbq;
int dp[MAXN];
int in[MAXN];
set<bbq> R, S;
int n, s, l;

int main()
{
    int i, j;
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &s, &l);
    for(i = 1; i <= n; i++)
        scanf("%d", &in[i]);
    j = 1;
    for(i = 1; i <= n; i++){
        S.insert(bbq(in[i], i));
        while(!S.empty() && S.rbegin()->first - S.begin()->first > s ){
            S.erase(bbq(in[j], j));
            j++;
        }
        if(i >= l && -1 != dp[i - l])
            R.insert(bbq(dp[i - l], i - l));
        while(!R.empty() && R.begin()->second < j - 1)
            R.erase(R.begin());
        dp[i] = R.empty() ? -1 : R.begin()->first + 1;
    }
    printf("%d\n", dp[n]);
    return 0;
}
