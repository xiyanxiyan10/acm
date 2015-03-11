/**
 * @brief Codeforces Round #295 (Div. 2) c
 * @file c.cpp
 * @author mianma
 * @created 2015/03/11 10:12
 * @edited  2015/03/11 10:12
 * @type math
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a))
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

//#define DEBUG 1
#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

#define MAXN 26
const int mod = 1e9+7;

typedef long long int ll;

int da;
int dg;
int dc;
int dt;

int n;
string str;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    CIN >> n >> str;
    for(int i = 0; i < (int)str.size(); i++){
        switch(str[i]){
            case 'A':
                ++da;
                break;
            case 'G':
                ++dg;
                break;
            case 'C':
                ++dc;
                break;
            case 'T':
                ++dt;
                break;
            default:
                break;
        }
    }
    int cnt = 0;
    int maxval = max(max(da, dg), max(dc, dt));
    if(da == maxval) ++cnt;
    if(dg == maxval) ++cnt;
    if(dc == maxval) ++cnt;
    if(dt == maxval) ++cnt;
    ll ans = 1LL;
    for(int i = 0; i < (int)str.size(); i++)
            ans = (ans*cnt)%(mod);
    ans = ans%mod;
    COUT << ans << "\n";

    return 0;
}



