/**
 * @brief good bye 2014 d
 * @file d.cpp
 * @author mianma
 * @created 2014/01/12  15:42
 * @edited  2014/01/12  15:42
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
#include <utility>
#include <iomanip>

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

int weight[MAXN];                       /*store all the weight for all path*/
ll  cuts[MAXN];                         /*tot edge cross all cuts*/                 
vector<pair<int, int>> tree[MAXN];      /*store tree for all pos*/
double e;                               /*expected val*/
double m;                                                                
int n, q;          

ll dfs(int prev, int curr){
    ll cnt = 1;
    for(int i = 0; i < tree[curr].size(); i++){
        int next = tree[curr][i].first;
        if(tree[curr][i].first == prev)
            continue;
            cnt += dfs(curr, next);
            ll lft = cnt;
            ll rht = n - cnt; 
            ll tot = 0;              /*count edge*/
            if(1 != rht)             /*lft choose 1, rht choose 2*/
                tot += lft*((rht * (rht - 1))/2);                      
            if(1 != lft)             /*lft choose 2, rht choose*/
                tot += rht*((lft * (lft - 1))/2);  
            cuts[tree[curr][i].second] = tot;
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    int a, b;
    m = n*(n - 1)*(n - 2)/6.0;
    for(int i = 1; i <= n - 1; i++){
        CIN >> a >> b >> weight[i];
        tree[a].push_back(make_pair(b, i));
        tree[b].push_back(make_pair(a, i));
    }
    dfs(0, a);
    e = 0.0;
    for(int i = 1; i <= n; i++)
        e += cuts[i] * 2 * weight[i];
    CIN >> q;
    COUT  << fixed << setprecision(24);
    int r, w;
    for(int i = 1; i <= q; i++){
        CIN >> r >> w;
        e -= cuts[r] * 2 * (weight[r] - w);
        COUT << e/m << "\n";
    }
    return 0;
}



