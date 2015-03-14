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
vector<int> g[MAXN]; //store the graph
int visit[MAXN];     //mark node visisted for dfs
int dep[2*MAXN];     //record dep of nodes visited
int node[2*MAXN];    //recors which in this dep vec
int pos[MAXN];       //first time this node visited
int sp[2*MAXN][20];   //spare table for rmq
int dep_cnt;         //tot element in dep and node

void dfs(int curr, int h){
    ++h;
    pos[curr] = dep_cnt; //first vistit this pos
    dep[dep_cnt] = h;
    node[dep_cnt] = curr;
    ++dep_cnt;
    visit[curr] = 1;
    for(int i = 0; i < g[curr].size();i++){
            int next = g[curr][i];
            if(visit[next])
                continue;
            dfs(next, h + 1);
            dep[dep_cnt] = h;
            node[dep_cnt] = curr;
            ++dep_cnt;
    }
}

int rmq_log(int n){
    int i;
    for(i = 0; 1<< i <= n; i++);
    return (i - 1);
}

void rmq_init()
{
    for(int i = 0; i < dep_cnt; i++)
        sp[i][0] = i;
    for(int j = 1; 1<< j <= dep_cnt; j++)
        for(int i = 0; (1 << j) + i - 1 < dep_cnt; i++){
            int a = sp[i][j - 1];
            int b = sp[ (1 << (j - 1)) + i][j - 1];
            sp[i][j] = dep[a] < dep[b] ? a : b;
        }
}

int rmq_search(int i, int j)
{
    if(i == j)
        return i;
    int k = rmq_log(j - i + 1);
    int a = sp[i][k];
    int b = sp[j - (1 << k) + 1][k];
    return (node[dep[a] < dep[b] ? a: b]);
}


int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    CIN >> n;
    int x, y;
    for(int i = 0; i < n; i++){
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
        COUT << rmq_search(pos[x], pos[y]) << endl;
    }
    return 0;
}



