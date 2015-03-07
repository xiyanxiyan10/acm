/**
 * @brief Codeforces Round #294 (Div. 2) b
 * @file b.cpp
 * @author mianma
 * @created 2015/02/28 9:40
 * @edited  2015/02/28 9:40
 * @type bgs
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

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

#define MAXN 20020

int n, m, ans;
int vis[MAXN];

int bfs(int n , int m){
    queue<int> p; 
    queue<int> q;
    p.push(n);      /*n 的值*/
    q.push(0);      /*step*/
    vis[n] = 1;

    while(!p.empty()){
        int v1 = p.front();
        int c1 = q.front();

        p.pop();
        q.pop();

        for(int i = 0; i < 2; i++){
            int v = v1; 
            int c = c1;

            if(0 == i)
                --v;
            else 
                v *= 2;

            if(v == m && !vis[v])
                return c + 1;

            if(v > 0 && v < MAXN && !vis[v]){
                p.push(v);
                q.push(c + 1);
                vis[v] = 1;
            }
        }   
    }
    return -1;
}


int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    CIN >> n >> m;
    COUT << ( m <= n ? n - m : bfs(n, m)) << "\n";
    return 0;
}



