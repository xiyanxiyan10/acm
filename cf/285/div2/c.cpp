/**
 * @brief Codeforces Round #285 (Div. 2) c
 * @file c.cpp
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
#include <vector>
#include <set>

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

#define MAXN 100000

int n;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    for(int i = 0 ; i < n; i++){
    
    }
    return 0;
}



