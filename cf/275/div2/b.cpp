/**
 * @brief Codeforces Round #275 (Div. 2) b
 * @file b.cpp
 * @author 面码
 * @created 2014/12/11 16:55
 * @edited  2014/12/11 16:55
 * @type  brute math
 * @TODO wait to test
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

/*calulate this from math*/
#define MAXN 1010

int cnt1, cnt2, x, y, i, j;
int need1, need2, need;

int st1, st2, st3;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> cnt1 >> cnt2 >> x >> y;
    double tmp = (double)cnt1 + (double)cnt2;
    i = max( (int)floor((-1 + sqrt(4*tmp + 1))/2), 2);

    for(j = i; j < MAXN; j++){
        int bmp = 0;
        if(j%x)
            bmp |= (1 << 0);
        if(j%y)
            bmp |= (1 << 1);
        if(3 == bmp)     /*element can distribute into both*/
            ++st3;
        else if(1 == bmp)
            ++st1;
        else if(2 == bmp)
            ++st2;
        else
            ;

        need1 = cnt1 - st1;
        need2 = cnt2 - st2;
        need  = (need1 > 0 ? need1 : 0) + (need2 > 0 ? need2 : 0);
        if(need > st3)
                continue;
        COUT << j << "\n";
        return 0;
    }
    return 0;
}



