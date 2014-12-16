/**
 * @brief uva 11464
 * @file 11464.cpp
 * @author mianma
 * @created 2014/12/16 17:53
 * @edited  2014/12/16 17:53
 * @type brute
 * @note
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <cmath>

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

#define INF  10000000
#define MAXN 20

int n, t;
int ans;
int base[MAXN][MAXN], record[MAXN][MAXN];

int solve(const int &bmp){
    int sum;
    for(int i = 0; i < n; i++){
        if(bmp& (1 << i))
            record[1][i + 1] = 1;
        else if(base[1][i + 1])
            return INF;
        else
            ;
    }
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= n; j++){
            sum = record[i - 2][j] + record[i - 1][j - 1] + record[i - 1][j + 1];   
            record[i][j] = sum & 0x1 ? 1 : 0;
            if(0 == record[i][j] && base[i][j])
                return INF;
        }
    sum = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(record[i][j] != base[i][j])
                    ++sum;
    return sum;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> t;
    for(int cases = 1; cases <= t; cases++){
        CIN >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                CIN >> base[i][j];

        /*brute start*/
        ans = INF;
        for(int i = 0; i < (1 << n); i++)
            ans = min(ans, solve(i));
        COUT << "Case " << cases << ": " << ans << "\n";
    }
    return 0;
}



