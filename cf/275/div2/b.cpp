/**
 * @brief Codeforces Round #275 (Div. 2) b
 * @file b.cpp
 * @author 面码
 * @created 2014/12/12 9:44
 * @edited  2014/12/12 9:44
 * @type  math binary search
 * 
 *
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include <string>
#include <set>
#include <cstring>
#include <cmath>
#include <vector>

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

#define MAXN (2e9 + 10)

typedef long long int ll;

ll lft, rht, mid;
ll cnt1, cnt2, x, y, z;
ll i, j, k;
ll need1, need2;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> cnt1 >> cnt2 >> x >> y;
    z = x*y;
    lft = 2; rht = MAXN;
    while(lft <  rht){
        mid = ((rht - lft)/2 + lft);
                                      /*set problem*/
        i = mid - mid/x;                            
        j = mid - mid/y;                    
        k = mid -  mid/z;              
        k = i + j - k;
        i -= k;
        j -= k;
#ifdef DEBUG
    COUT << i << " " << j << " " << k << "\n";
#endif

        if(i < cnt1)
            k = k - (cnt1 - i);
        if(j < cnt2)
            k = k - (cnt2 - j);

        if(k < 0)
            lft = mid + 1;           /*need mote element*/
        else
            rht = mid;               /*may get an answer more better*/
    }
    COUT << lft << endl;
    return 0;
}



