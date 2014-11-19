/**
 * @brief Codeforces Round #277.5 (Div. 2) d
 * @file d.cpp
 * @author 面码
 * @created 2014/11/19 17:07
 * @edited  2014/11/19 17:07
 * @type dfs brute
 * @TODO test
 */
#include <cstdio>
#include <cstring>
#include <stack>
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
int color[MAXN];
int count[MAXN];

vector<int>tree[MAXN];
stack<int> st;

enum COLOR{
    WHITE = 0,
    GRAY,
    BLACK,
};

void dfs(int root){
    int from, to, idx;
    color[root] = GRAY;
    st.push(root);
    while(!st.empty()){
        from = st.top();
        st.pop();
        for(idx = 0; idx < tree[from].size(); idx++){
            to = tree[from][idx];
                if(WHITE != color[to]){
                    if(BLACK == color[to]){
                        count[to]++;
#ifdef DEBUG
                        printf("Get black in %d\n", to);
#endif
                    }
                }else{
                    color[to] = GRAY;
                    st.push(to);
                }
        }
        color[from] = BLACK;
    }
}

int main()
{
    int i, j, k, tmp;
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
    for(i = 1; i <= n; i++){
        CLR(color);
        CLR(count);
        dfs(i);
        for(j = 1; j <= n; j++)
            if(count[j]){
                ans++;
            }
    }
    printf("%d\n", ans);
    return 0;
}
