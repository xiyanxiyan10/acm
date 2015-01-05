/**
 * @brief live archive 3029
 * @file 3029.cpp
 * @author mianma
 * @created 2015/01/05 14:18
 * @edited  2015/01/05 14:18
 * @type dp
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

int table[MAXN][MAXN];
int up[MAXN][MAXN];
int lft[MAXN][MAXN];
int rht[MAXN][MAXN];
int m, n, ans, cases;

static inline void input(void){
    char ch;
    CLR(up);
    CLR(rht);
    CLR(lft);
    CLR(table);
    ans = 0;
    CIN >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            CIN >> ch;
            if(ch == 'R') table[i][j] = 1;
        }
}

static inline void output(void){
        COUT << ans << "\n";
}

static inline void solve(void){
    int record;
    for(int i = 1; i <= m; i++){
        record  = 0;
        for(int j = 1; j <= n; j++){    /*check from lft to rht*/
            if(!table[i][j]){
                                        /*try to reset status for lft*/
                lft[i][j] = lft[i - 1][j] == 0 ? 1 : lft[i - 1][j];
                lft[i][j] = max( lft[i][j], record + 1);
                up[i][j] = up[i - 1][j] + 1;
            }else{
                record = j;
            }
        }
        record = n + 1;
        for(int j = n; j >= 1; j--){    /*check from rht to lft*/
            if(!table[i][j]){
                                        /*try to reset status for rht*/
                rht[i][j] = rht[i - 1][j] == 0 ? n : rht[i - 1][j];
                rht[i][j] = min( rht[i][j], record - 1);
                ans = max( ans, up[i][j] * (rht[i][j] - lft[i][j] + 1));
            }else{
                record = j;
            }
        }
    }
    ans *= 3;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",   ios::in);
    COUT.open("./out", ios::out);
#endif
    CIN >> cases;

    while(cases--){
        input();
        solve();
        output();
    }
    return 0;
}



