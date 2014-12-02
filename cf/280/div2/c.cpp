/**
 * @brief Codeforces Round #280 (Div. 2) c
 * @file c.cpp
 * @author mianma
 * @created 2014/12/02 14:38
 * @edited  2014/12/02 14:38
 * @type math
 * @note 
 *      TL occured with n^2 sort 
 *      so cost < nlgn  sort will ac
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

#define MAXN 100010

int n, r, avg;
long long int ans;
long long int tot;
long long int curr;

struct exam{
    int grade;
    int cost;
};

struct exam table[MAXN]; 

static inline int cmp(const void *lft, const void *rht){
        return (((const struct exam *)lft)->cost - ((const struct exam*)rht)->cost );
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n >> r >> avg;
    for(int i = 0; i < n; i++){
            CIN  >> table[i].grade >> table[i].cost;
            curr += table[i].grade;
    }

    tot = n * (long long int )avg - curr;
    if(tot <= 0 ){
            COUT << ans << "\n";
            return 0;
    }

    /*sort*/
    qsort(table, n, sizeof(table[0]), cmp);

    ans = 0;
    /*greedy*/
    for(int i = 0; i < n && tot; i++){
        long long int  cnt;
        cnt = min(r - table[i].grade, tot);
        tot -= cnt;
        ans += cnt * table[i].cost;
    }
    COUT << ans << "\n";
    return 0;
}



