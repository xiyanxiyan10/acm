/**
 * @brief good bye 2014 d
 * @file d.cpp
 * @author mianma
 * @created 2014/01/07  15:42
 * @edited  2014/01/07  15:42
 * @type dfs tree 
 * @note 
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

ll cuts[MAXN];                      /*tot network cross this cut*/

double expected;                    /*expected val*/
int n, q;

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

    /*output*/

    return 0;
}



