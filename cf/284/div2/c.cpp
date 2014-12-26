/**
 * @brief Codeforces Round #284 (Div. 2) c
 * @file c.cpp
 * @author mianma
 * @created 2014/12/26 14:43
 * @edited  2014/12/26 14:43
 * @type geometry
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <map>

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

int n;
ll x1, y1, x2, y2;
ll a, b, c;
int ans;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> x1 >> y1 >> x2 >> y2;
    CIN >> n;
    ans = 0;
    for(int i = 0; i < n; i++){
        CIN >> a >> b >> c;
        ll lft = a*x1 + b*y1 + c;
        ll rht = a*x2 + b*y2 + c;
        if( lft > 0 && rht < 0 || lft < 0 && rht > 0)
            ++ans;
    }
    COUT << ans << "\n";
    return 0;
}



