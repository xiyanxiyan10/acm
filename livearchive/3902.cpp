/**
 * @brief live archive 3902
 * @file 3902.cpp
 * @author mianma
 * @created 2014/12/24 15:03
 * @edited  2014/12/24 15:03
 * @type dfs 
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

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

#define MAXN     (1000 + 10)
vector<int> gr[MAXN];
vector<int> leaf[MAXN];
int fa[MAXN];
int visited[MAXN];

int n, k, s, cases;
int lft, rht;
int ans;

/*dep start from zero*/
void pre_dfs(int curr, int prev, int dep){
    fa[curr] = prev;
    if(1 == gr[curr].size()){           /*leaf*/
        leaf[dep].push_back(curr);
        return;
    }
    ++dep;
    for(int i = 0; i < gr[curr].size(); i++){
            int next = gr[curr][i];
            if(next == prev)
                continue;
            pre_dfs(next, curr, dep);
    }
}

/*dep start from zero*/
void update_dfs(int curr, int prev, int dep, int maxdep){
    if(dep > maxdep)
        return;
    if(1 == gr[curr].size()){       /*leaf*/
            visited[curr] = 1;  
            return;
    }
    ++dep;
    for(int i = 0; i < gr[curr].size(); i++){
            int next = gr[curr][i];
            if(next == prev)
                continue;
            update_dfs(next, curr, dep, maxdep);
    }
}

/*init case*/
void init_case(void){
    for(int i = 0; i <= n; i++){
            leaf[i].clear();
            gr[i].clear();
    }
    CLR(fa);
    CLR(visited);
    ans = 0;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",   ios::in);
    COUT.open("./out", ios::out);
#endif
    CIN >> cases;

    while(cases--){
        CIN >> n;
        CIN >> s >> k;
        init_case();

        for(int i = 0; i < n - 1 ; i++){
           CIN >> lft >> rht;
            gr[lft].push_back(rht);
            gr[rht].push_back(lft);
        }

        pre_dfs(s, s, 0);
        update_dfs(s, s, 0, k);

        for(int i = n; i >= 1; i--){
            for(int j = 0; j < leaf[i].size(); j++){
                int idx = leaf[i][j];
                if(visited[idx])
                    continue;
                for(int dep = 0; dep < k && fa[idx] != idx ; dep++)
                    idx = fa[idx];
                update_dfs(idx, idx, 0, k);
                ++ans;
            }
        }
        COUT << ans << "\n";
    }
    return 0;
}



