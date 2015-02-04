/**
 * @brief Codeforces Round #290 (Div. 2) b
 * @file a.cpp
 * @author mianma
 * @created 2015/02/04 15:17
 * @edited  2015/02/04 15:17
 * @type brute
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
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

#define MAXN 55
#define MAXD 4

char g[MAXN][MAXN];
int vis[MAXN][MAXN];

struct s_dir{
    int x;
    int y;
}dir[MAXD] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1},
};

int m, n;
int xb, yb;

static inline bool brute(int x, int y, char color, int cnt){
    if(x <= 0 || x > m || y <= 0|| y > n || g[x][y] != color) return false;
#ifdef  DEBUG
    //COUT << x << " " << y << "->" << cnt << "|||" << m << " " << n << " " << color << "\n" ;
#endif
    if(vis[x][y]){
        if(xb == x && yb == y && cnt >= 4)
            return true;
        else
            return false;
    }
    vis[x][y] = true;
    for(int i = 0; i < MAXD; i++){
            if(brute(x + dir[i].x, y + dir[i].y, color, cnt + 1))
                    return true;
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> m >> n;
    int cnt;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
                CIN >> g[i][j];
        }

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            CLR(vis);
            xb = i, yb = j;
            cnt = 1;
            if(brute(i, j, g[i][j], cnt)){
                COUT << "Yes\n"; 
                return 0;
            }
        }
    COUT << "No\n";
    return 0;
}



