/**
 * @brief Codeforces Round #283 (Div. 2) a
 * @file a.cpp
 * @author mianma
 * @created 2014/12/18 17:45
 * @edited  2014/12/18 17:45
 * @type brute
 * @note
 */
#include <fstream>
#include <iostream>
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

#define MAXN 105
#define INF  1000100

int n;
int table[MAXN];
int ans = INF;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    for(int i = 0; i < n; i++){
        CIN >> table[i]; 
    }

    for(int i = 1; i < n - 1; i++){
        int tmp = -1;
        for(int j = 1; j < n; j++){
            if(i == j)
                continue;
            else if(i + 1 == j)
                tmp = max( tmp, table[j] - table[j - 2] );
            else
                tmp = max( tmp, table[j] - table[j - 1] );
        }
        ans = min(tmp, ans);
    }
    COUT << ans << "\n";
    return 0;
}



