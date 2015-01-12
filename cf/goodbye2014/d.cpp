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
ll  counter[MAXN];                      /*counter all node in this subtree*/
vector< pair<int, int> > tree[MAXN];    /*store tree for all pos*/
long double e;                               /*expected val*/
double m;                                                                
int n, q;          

void dfs(int prev, int curr){
    counter[curr] = 1;
    for(int i = 0; i < tree[curr].size(); i++){
        int next = tree[curr][i].first;
        int edge = tree[curr][i].second;
        if(prev == next)
            continue;
        dfs(curr, next);
        counter[curr] += counter[next];
        ll lft = counter[next];
        ll rht = n - lft; 
        ll tot = 0;              /*count edge*/
        if(1 != rht)             /*lft choose 1, rht choose 2*/
            tot += lft*((rht * (rht - 1))/2);                      
        if(1 != lft)             /*lft choose 2, rht choose 1*/
            tot += rht*((lft * (lft - 1))/2);  
        cuts[edge] = tot;
    }
#ifdef DEBUG
    COUT << curr << "->" << counter[curr] << endl;
#endif
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
    for(int i = 1; i <= n - 1; i++)
        e += cuts[i] * 2.0 * weight[i];
    CIN >> q;
    COUT  << fixed << setprecision(10);
    int r, w;
    for(int i = 1; i <= q; i++){
        CIN >> r >> w;
        e -= cuts[r] * 2.0 * (weight[r] - w);
        weight[r] = w;
        COUT << e/m << "\n";
    }
    return 0;
}



