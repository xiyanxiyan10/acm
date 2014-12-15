/**
 * @brief Codeforces Round #282 (Div. 2) b
 * @file b.cpp
 * @author mianma
 * @created 2014/12/15 11:52
 * @edited  2014/12/15 11:52
 * @type math
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

int a, b, c, cnt;
double cf;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> a >> b; 
    if(a == b){
        COUT << "infinity\n";
        return 0;
    }
    if(a < b){
        COUT << "0\n";
        return 0;
    }
    a -= b;
    cf = sqrt((double)a);
    c = (int)floor(cf + 0.5);
    cnt = 0;
    for(int i = 1; i <= c; i++){
        if( 0 == a%i){
                if(a/i > b)
                    ++cnt;
                if(i > b)
                    ++cnt;
        }
    }
#ifdef DEBUG
    COUT << cf << " <-> " << c << "\n";
#endif
    if(cf == c && 0 == a%c && c > b)
            --cnt;
    COUT << cnt << "\n";
    return 0;
}



