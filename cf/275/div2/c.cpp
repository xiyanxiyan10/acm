/**
 * @brief Codeforces Round #275 (Div. 2) c
 * @file c.cpp
 * @author 面码
 * @created 2014/12/10 16:54
 * @edited  2014/12/10 16:54
 * @type  math
 *
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include <string>
#include <set>
#include <cstring>
#include <cmath>
#include <vector>

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

#define MAXN 100010
int n, k;

int table[MAXN];

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n >> k;
    int idx = 1;
    int flag = 1;
    COUT << idx << " ";
    for(int i = k; i > 0; i--){
        if(0 == flag)
            idx -= i;
        else
            idx += i;
        COUT << idx << " ";
        flag ^= 1;
    }
    for(idx = k + 2; idx <= n; idx++)
            COUT << idx << " ";
    COUT << "\n";
    return 0;
}



