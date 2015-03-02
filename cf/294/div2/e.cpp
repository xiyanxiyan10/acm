/**
 * @brief Codeforces Round #294 (Div. 2) d
 * @file d.cpp
 * @author mianma
 * @created 2015/03/02 13:24
 * @edited  2015/03/02 13:24
 * @type dfs
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
map<int, int> ans[MAXN];
int visit[MAXN];

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

    //dfs here 
    //
    CIN >> q;
    for(int i = 0; i < q; i++){
        CIN >> x >> y;
        COUT << ans[x][y] << endl;
    }   
    return 0;
}



