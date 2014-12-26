/**
 * @brief Codeforces Round #284 (Div. 2) b
 * @file b.cpp
 * @author mianma
 * @created 2014/12/26 11:51
 * @edited  2014/12/26 11:51
 * @type brute
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))
#define PI         acos(-1.0)

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

int n, m;
string lft, rht, str;
map<string, string> table;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n >> m;
    for(int i = 0; i < m; i++){
        CIN >> lft >> rht;
        if(lft.size() <= rht.size())
                rht = lft;
        table[lft] = rht;
    }
    for(int i = 0; i < n; i++){
        CIN >> str;
        COUT << table[str];
        COUT << (i == n - 1 ? "\n":" ");
    }
    return 0;
}



