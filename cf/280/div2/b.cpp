/**
 * @brief Codeforces Round #280 (Div. 2) b
 * @file b.cpp
 * @author mianma
 * @created 2014/12/02 11:20
 * @edited  2014/12/02 11:20
 * @type math
 * @note
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

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

#define MAXN 1010
#define MAXL 1000000010

double lanterns[MAXN];
double d = 0.0;
int n;
double l;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n >> l;
    for(int i = 0; i < n; i++)
            CIN >> lanterns[i];
    sort(lanterns, lanterns + n); 
    
    d  = max(d, lanterns[0]);                /*first one*/
    d  = max(d, l - lanterns[n - 1]);        /*last one*/
    
    for(int i = 1; i < n; i++)
        d = max(d, (lanterns[i] - lanterns[i - 1])/2);
    
    COUT << fixed << setprecision(10) << d << "\n";
    return 0;
}



