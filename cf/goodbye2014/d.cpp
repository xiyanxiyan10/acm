/**
 * @brief good bye 2014 d
 * @file d.cpp
 * @author mianma
 * @created 2014/01/07  15:42
 * @edited  2014/01/07  15:42
 * @type dfs tree 
 * @note fail
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

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

#define MAXN (100000 + 10)

typedef long long int ll;

int weight[MAXN];                   /*store all the weight for all path*/

struct edge{
    int idx;                        /*idx of the path*/
    int from;                       /*the src for the edge*/
    int to;                         /*the dst for the edge*/
};
vector<struct edge> tree[MAXN];     /*store tree for all pos*/

struct convert{
    int idx;                        /*idx for the edge*/
    int weight;                     /*new weight for this edge*/              
};
vector<struct convert> changes;     /*store all changes*/   

vector<int> dp;                     /*record all tot weight to pos visited*/

int visit[MAXN];                    /*mark all pos visited*/

int cuts[MAXN];                     /*pos one the lft of this   cuts*/

double expected = 0.0;              /*expected val*/
int n, q;

void dfs(int root){
    struct edge eg;                 /*edge this pos from*/
    int pos_cnt = 0;                /*record the tot pos visited*/
    int curr, next;
    eg.to =   root;
    eg.from = -1;
    eg.idx = -1;
    stack<struct edge> st;
    st.push(eg);
    visit[root] = 1;
    while(!st.empty()){
            eg       = st.top();
            st.pop();
            curr      = eg.to;
            if(eg.from >= 0){                       /*ignore root pos*/
                double tot_added    = 0.0;
                                                    /*calculate ans*/
                

                cuts[eg.idx] = pos_cnt;             /*update cuts*/
                for(int i = 0; i < dp.size(); i++)  /*update weight*/
                    dp[i] += weight[eg.idx];         
                dp.push_back(weight[eg.idx]);
            }
            ++pos_cnt;                              /*update pos cnt*/
            for(int i = 0; i <= tree[curr].size(); i++){
                    eg = tree[curr][i];
                    curr  = eg.to;
                    if(visit[curr])                 /*ignore node visited*/
                        continue;
                    st.push(eg);
            } 
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    int a, b;
    struct edge eg;
    for(int i = 0; i < n; i++){
        CIN >>  a >> b >> weight[i];
        eg.from = a;
        eg.to   = b;
        eg.idx  = i;
        tree[a].push_back(eg);
        eg.from = b;
        eg.to   = a;
        tree[b].push_back(eg);
    }
    CIN >> q;
    struct convert con;
    for(int i = 0; i < q; i++){
        CIN  >> con.idx >> con.weight;
        changes.push_back(con);
    }
    /*dfs*/
    dfs(a);     /*we choose one pos ans the root*/

    /*output*/
    return 0;
}



