/**
 * @brief Codeforces Round #279 (Div. 2) d
 * @file d.cpp
 * @author 面码
 * @created 2014/12/09 10:58
 * @edited  2014/12/09 10:58
 * @type math greedy
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 4000

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

ll a, b, c, d;
ll ans, a1, b1, c1, d1;
ll c12, c13, c22, c23;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> a >> b >> c >> d;
    ans = 0;

    a1 = a, b1 = b, c1 = c, d1 = d;
    c13 = 0; c23 = 0;
    while(0 == a1%3 && a1) a1 /= 3, c13++;
    while(0 == b1%3 && b1) b1 /= 3, c13++;
    while(0 == c1%3 && c1) c1 /= 3, c23++;
    while(0 == d1%3 && d1) d1 /= 3, c23++;

    while(c13 > c23 && 0 == a%3 && a) c13--, a = a*2/3, ans++;
    while(c13 > c23 && 0 == b%3 && b) c13--, b = b*2/3, ans++;
    while(c13 < c23 && 0 == c%3 && c) c23--, c = c*2/3, ans++;
    while(c13 < c23 && 0 == d%3 && d) c23--, d = d*2/3, ans++;

    a1 = a, b1 = b, c1 = c, d1 = d;
    c12 = 0; c22 = 0;
    while(0 == a1%2 && a1) a1 /= 2, c12++;
    while(0 == b1%2 && b1) b1 /= 2, c12++;
    while(0 == c1%2 && c1) c1 /= 2, c22++;
    while(0 == d1%2 && d1) d1 /= 2, c22++;

    while(c12 > c22 && 0 == a%2 && a) c12--, a /= 2, ans++;
    while(c12 > c22 && 0 == b%2 && b) c12--, b /= 2, ans++;
    while(c12 < c22 && 0 == c%2 && c) c22--, c /= 2, ans++;
    while(c12 < c22 && 0 == d%2 && d) c22--, d /= 2, ans++;

    if(a *b != c*d){
        COUT << "-1\n";
        return 0;
    }
    COUT << ans << "\n";
    COUT << a << " " << b << "\n";
    COUT << c << " " << d << "\n";
    return 0;
}



