/**
 * @brief Codeforces Round #284 (Div. 2) a
 * @file a.cpp
 * @author mianma
 * @created 2014/12/26 11:51
 * @edited  2014/12/26 11:51
 * @type brute
 * @note
 */
#include <fstream>
#include <iostream>
#include <cstring>

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

#define MAXN 50
#define MAXV 1e5

int n, x;
int curr, ans, lft, rht;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n >> x;
    int curr = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        CIN >> lft >> rht;
        if(curr > lft)
            lft = curr;
        ans += (lft - curr)%x + rht - lft + 1;
        curr = rht + 1;
    }
    COUT << ans  << "\n";
    return 0;
}



