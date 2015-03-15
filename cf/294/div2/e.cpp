/**
 * @brief Codeforces Round #294 (Div. 2) e
 * @file e.cpp
 * @author mianma
 * @created 2015/03/02 13:24
 * @edited  2015/03/02 13:24
 * @type lca
 * @todo debug
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a))
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

//#define DEBUG 1

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

#define MAXN 100010

int n, q;
int ans;
vector<int> g[MAXN]; //store the graph
int fa[MAXN];        //father of each node
int dep[MAXN];       //record dep of nodes visited
int num[MAXN];       //nums of nodes in this subtree
int sp[MAXN][20];    //spare table for rmq

#define DEG    20   //max father

static inline void swap1(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}

void dfs(int curr, int prev, int h){
    ++h;
    num[curr] = 1;
    fa[curr] = prev;
    dep[curr] = h;
    for(int i = 0; i < g[curr].size();i++){
            int next = g[curr][i];
            if(next == prev)
                continue;
            dfs(next, curr, h + 1);
            num[curr] += num[next];
    }
}

void lca_init()
{
    for(int i = 1; i <= n ; i++)
        sp[i][0] = fa[i];

    for(int j = 1; 1<< j < n; j++)
        for(int i = 1; i <= n; i++){
            if(sp[i][j - 1])
                sp[i][j] = sp[sp[i][j - 1]][j - 1];
        }
}

/*find the cnt' father of this pos*/
int lca_up(int x, int cnt){
    for(int i = 0, j = cnt; j; j>>= 1, i++)
        if(j&0x1)
            x = sp[x][i];
        return x;
}

/*find the lca for two node*/
int lca_find(int x, int y)
{
    if(dep[x] < dep[y]) swap1[x][y];
    lca_up(x, dep[x] - dep[y]);
    if(x == y) return x;
    for(int i = DEG; i >= 0; i--)
        if(sp[x][i] && sp[y][i] && sp[x][i] != sp[y][i]){
                x = sp[x][i];
                y = sp[y][i];
        }
    return fa[x];
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    CIN >> n;
    int x, y;
    for(int i = 0; i < n - 1; i++){
        CIN >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(x, x, 0);
    lca_init();
    CIN >> q;
    for(int i = 0; i < q; i++){
        CIN >> x >> y;
        int lca = lca_find(x, y);
        int lft = dep[lca] - dep[x];
        int rht = dep[lca] - dep[y];
        int mid = (lft + rht)/2;
        if( (lft + rht) &0x1)
                ans = 0;
        else if(lft == rht)
                ans = n - num[lca_up(x, dep[x] - dep[lca] - 1)] - num[lca_up(y, dep[y]- dep[lca] - 1)];
        else if(lft > rht)
                ans = n - num[lca_up(x, mid)] - num[lca_up(x, mid - 1)];
        else
                ans = n - num[lca_up(y, mid)] - num[lca_up(y, mid - 1)];
        COUT << ans << "\n";
    }
    return 0;
}



