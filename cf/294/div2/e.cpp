/**
 * @brief Codeforces Round #294 (Div. 2) e
 * @file e.cpp
 * @author mianma
 * @created 2015/03/02 13:24
 * @edited  2015/03/02 13:24
 * @type lca
 * @todo ac fail
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
vector<int> g[MAXN];  //store the graph
int fa[MAXN];         //father of each node
int height[MAXN];     //record height of nodes visited
int num[MAXN];        //nums of nodes in this subtree
int sp[MAXN][20];     //spare table for rmq

int deg;              //init the max deg 

/*exchange two value*/
void swap1(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}

/*deep first search, record the fa and the height*/
void dfs(int curr, int prev, int h){
#ifdef DEBUG
    COUT << curr << " -> "<< h << "\n";
#endif
    num[curr] = 1;
    fa[curr] = prev;
    height[curr] = h;
    for(int i = 0; i < g[curr].size();i++){
            int next = g[curr][i];
            if(next == prev)
                continue;
            dfs(next, curr, h + 1);
            num[curr] += num[next];
    }
}

/*init the limit*/
void deg_init()
{
    for(deg = 0; 1 << deg < n; deg++);
    deg--;
}

/*init the sparse table*/
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

/*find the cnt's father of this pos*/
int lca_up(int x, int cnt){
    for(int i = 0, j = cnt; j; j>>= 1, i++){
        if(j&0x1)
            x = sp[x][i];
    }
    return x;
}

/*find the lca for two node*/
int lca_find(int x, int y)
{
    if(height[x] < height[y]) 
        swap1(x, y);
    /*move the node x up to the y's dep*/
    lca_up(x, height[x] - height[y]);
    /*if x == y, we get the node*/
    if(x == y) return x;
    for(int i = deg; i >= 0; i--)
        if(sp[x][i] && sp[y][i] && sp[x][i] != sp[y][i]){
            /*we move two node more and more close to each other*/
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
    /*build the map*/
    for(int i = 0; i < n - 1; i++){
        CIN >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    deg_init();
    /*dfs the graph and collect info*/
    dfs(1, 1, 0);
    /*init sparse table*/
    lca_init();
    CIN >> q;
    for(int i = 0; i < q; i++){
        CIN >> x >> y;
        int lca = lca_find(x, y);               /*find the lca of two node*/
        int lft = height[x] - height[lca];      /*get the lft height*/
        int rht = height[y] - height[lca];      /*get the rht height*/
        int mid = (lft + rht)/2;                /*get the dist*/
#ifdef DEBUG
        COUT << "lca = " << lca << ",lft = " << lft << ",rht = " << rht << endl;
#endif
        if( (lft + rht) &0x1)                   /*odd dist*/
                ans = 0;
        else if(lft == rht)
                ans = n - num[lca_up(x, height[x] - height[lca] - 1)] - num[lca_up(y, height[y]- height[lca] - 1)];
        else if(lft > rht){
                int pos = lca_up(x, mid - 1);
                ans = num[fa[pos]] - num[pos];
        }else{
                int pos = lca_up(y, mid - 1);
                ans = num[fa[pos]] - num[pos];
        }
        COUT << ans << "\n";
    }
    return 0;
}



