/**
 * @brief Codeforces Round #286 (Div. 2) b
 * @file b.cpp
 * @author mianma
 * @created 2014/01/19 15:02
 * @edited  2014/01/19 15:02
 * @type brute
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stack>
#include <set>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

#define MAXN 110

int n, m, q;
int  ans[MAXN][MAXN];
int visited[MAXN];
vector<int> color_vec;
vector<int> g[MAXN][MAXN];

/*add color into map ad return the id for the color*/
int color_to_id(int color){
    for(int i = 0; i < color_vec.size(); i++){
        if(color_vec[i] == color)
            return i;
    }
    color_vec.push_back(color);
    return color_vec.size() - 1;
}

/*wether the edge added in map ?*/
int find_edge(vector<int> *gf, int from, int to){
    for(int i = 0; i < gf[from].size(); i++)
        if(gf[from][i] == to)
                return 0;
    return -1;
}

void dfs(vector<int> *gf, int root){
        stack<int> st;
        st.push(root);
        while(!st.empty()){
            int curr = root;
            ++ans[root][curr];
            visited[curr] = 1;
            for(int i = 0; i < gf[curr].size(); i++){
                int next = gf[curr][i];
                    if( visited[next])
                        continue;
                st.push(next);
            }
        }
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n >> m;
    int from, to, color;
    for(int i = 0; i < m; i++){
        CIN >> from >> to >> color;
        int id = color_to_id(color);
        vector<int> *gf = g[id];
        if(find_edge(gf, from, to) < 0){
                gf[from].push_back(to);
                gf[to].push_back(from);
        }
    }
    /*browser all color*/
    for(int i = 0; i < color_vec.size(); i++){
        vector<int> *gf = g[i];
        for(int j = 1; j <= n; j++){
            CLR(visited);
            /*dfs all vec*/
            dfs(gf, j);     
        }
    }
    CIN >> q;
    for(int i = 0; i < q; i++){
        CIN >> from >> to;
        COUT << ans[from][to] << "\n";
    }
    return 0;
}



