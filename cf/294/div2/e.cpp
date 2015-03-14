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
#include <map>

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
vector<int> g[MAXN];

int visit[MAXN];
int dep[2*MAXN];
int dep_cnt;
int pos[MAXN];
int sp[MAXN][6];

void dfs(int curr, int h){
    ++h;
    pos[curr] = dep_cnt;
    dep[dep_cnt++] = h;
    visit[curr] = 1;
    for(int i = 0; i < g[curr].size();i++){
            int next = g[curr][i];
            if(visit[next])
                continue;
            dfs(next, h + 1);
    }
    dep[dep_cnt++] = h;
}

int rmq_log(int n){
    int i;
    for(i = 0; 1<< i <= n; i++);
    return (i - 1);
}

void rmq_init()
{
    for(int i = 0; i < n; i++)
        sp[i][0] = i;
    for(int j = 1; 1<< j <= n; j++)
        for(int i = 0; (1 << i) + j - 1 < n; i++)
                sp[i][j] = dep[sp[i][j - 1]] < dep[sp[ (1 << (j - 1)) + i][j -1] ? sp[i][j - 1] : sp[ (1 << (j - 1)) + i][j - 1];

}

int rmq_search(int i, int j)
{
    if(i == j)
        return i;
    int k = rmq_log( j - i + 1);
    return( dep[sp[i][k - 1]] < dep[sp[ (1 << (k - 1)) + i][j -1] ? sp[i][k - 1] : sp[ (1 << (k - 1)) + i][k - 1]);

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
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(x, 0);
    rmq_init();

    CIN >> q;
    for(int i = 0; i < q; i++){
        CIN >> x >> y;
        x--;y--;
        COUT << rmq_search(x, y) << endl;
    }
    return 0;
}



