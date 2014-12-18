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
#define INF   1000100

int n;
int table[MAXN];
int ans = INF;
int lft, rht;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    for(int i = 0; i < n; i++){
        CIN >> table[i]; 
        if(i >= 1)
            ans = min(ans, table[i]  - table[i - 1]);
    }

    for(int i = 0; i < n; i++){
        if(0 == i|| n - 1 == i){
            continue;
        }
        ans = min(ans, table[i + 1] - table[i - 1]);
    }
    return 0;
}



