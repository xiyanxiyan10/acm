/**
 * @brief Codeforces Round #280 (Div. 2) d
 * @file d.cpp
 * @author mianma
 * @created 2014/12/04 11:46
 * @edited  2014/12/04 11:46
 * @type math
 * @note 
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cstdlib>

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

typedef long long int ll;

int x, y, n;
ll lft, rht, mid, a;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n >> x >> y;
    while(n--){
        CIN >> a;
        lft = 0, rht = max(x, y)*(1e9) + 1;
        while(lft < rht){
            mid = ((rht - lft)>>1) + lft;
            if(mid/x + mid/y < a)
                lft = mid + 1;
            else
                rht = mid;
        }
#ifdef DEBUG
    COUT << lft << "<->" << rht << "\n";
#endif
        
        if( 0 == rht%x && 0 == rht%y){
            COUT << "Both\n";
        }else if(0 == rht%x){
            COUT << "Vova\n"; 
        }else{
            COUT << "Vanya\n";
        }
    }
    return 0;
}



