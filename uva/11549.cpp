/**
 * @brief uva 11549
 * @file 11549.cpp
 * @author mianma
 * @created 2014/12/31 11:43
 * @edited  2014/12/31 11:43
 * @type 
 * @note floyd
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

#define MAXB 25

typedef long long int ll;

int t, n;
ll k;

ll next(int n, ll num){
    static int buf[MAXB];
    ll tmp = num*num;
    int cnt = 0;
    while(tmp != 0){
        buf[cnt++] = tmp%10;
        tmp /= 10;
    }
    n = min(n, cnt);
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans = ans*10 + buf[--cnt];
    return ans;
}

int solve(int n, ll k){
    ll t1, t2, ans;
    t1 = t2 = ans = k;
    do{
        t1 = next(n, t1);
        t2 = next(n, t2);
        ans = max(t2, ans);
        t2 = next(n, t2);
        ans = max(t2, ans);
    }while(t1 != t2);
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> t;
    for(int cases = 1; cases <= t; cases++){
        CIN >> n >> k;
        COUT << solve(n, k) << "\n";
    }
    return 0;
}



