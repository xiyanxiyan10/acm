/**
 * @brief Codeforces Round #277 (Div. 2) d
 * @file d.cpp
 * @author 面码
 * @created 2014/11/17 15:00
 * @edited  2014/11/17 15:00
 * @type dfs dp
 * @TODO ac
 *
 */
#include <cstdio>
#include <vector>

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))

#define MOD 1000000007
#define MAXN 2014

using namespace std;

typedef long long int ll;

int d, n;
int u, v;

int val[MAXN];
vector<int> tree[MAXN];

/**
 * @brief dfs and try to add new node
 * @param[in] root start pos;
 * @param[in] base  edge start pos
 * @param[in] curr  edge end pos
 * @note 
 *
 */
int dfs(int root, int base, int curr){
    int ans, to;
    /*make sure root with min val, and min idx if there is a node with the same val in case of conflict*/

    if(base)
    if((val[curr] - val[root] > d) || val[curr] <  val[root] || ( val[curr] == val[root] && curr < root))   
            return 0;

    ans = 1;
    for(int i = 0; i < tree[curr].size(); i++){
        to = tree[curr][i];
        if(to == base)
            continue;
        ans = (ll)ans * (1 + dfs(root, curr, to))%MOD;
    }
    return ans;
}

int main(void){
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d", &d, &n);
    for(int i = 1; i <= n; i++)
            scanf("%d", &val[i]);
    for(int i = 1; i < n;  i++){
            scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
    }

    int ans  = 0;
    
    for(int i = 1; i <= n; i++)
        ans = (ans + dfs(i, 0, i))%MOD;
    
    printf("%d\n", ans);
    return 0;
}

