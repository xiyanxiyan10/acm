/**
 * @brief jiu du 1387
 * @file 1387.cpp
 * @author mianma
 * @created 2015/01/21 18:09
 * @edited  2015/01/21 18:09
 * @type 
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef long long int ll;

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

int n;

int main()
{
    //ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    while(CIN >> n){
        ll pp, p, c;   /*see, prev prev, prev, curr*/ 
        if(0 == n){
            COUT << "0\n";
            continue;
        }
        if(1 == n){
            COUT << "1\n";
            continue;
        }
        p = 0;
        c = 1;
        --n;
        while(n--){
            pp = p;
            p = c;
            c = pp + p;
        }
        COUT << c << "\n";
    }
    return 0;
}
