/**
 * @brief Codeforces Round #285 (Div. 2) d
 * @file d.cpp
 * @author mianma
 * @created 2015/01/22 17:22
 * @edited  2015/01/22 17:22
 * @type math tree
 * @notea
 * @TODO take a reset 
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <stack>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))
#define PI         acos(-1.0)

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

/*api for binary index tree*/
static inline int low_bit(int i){
    return ( i & ( - i));
}

/*
static inline void build_bit(int *vec, int *bit, int size){
    for(int i = 1; i <= size; i++){
            bit[i] = vec[i];
            for(int j = i - 1; j > i - low_bit(i); j-= low_bit(j))
                bit[i] += bit[j];
    }
}
*/

static inline int sum_bit(int *bit, int k){
    int ans = 0;
    for(int i = k; i > 0; i -= low_bit(i))
        ans += bit[i];
    return ans;
}

static inline void update_bit(int *bit, int size, int i, int val){
    for(int j = i; j <= size; j += low_bit(j))
            bit[j] += val;
    
}

#define MAXN 200010

int n;
int p[MAXN];
int q[MAXN];
int bit[MAXN];

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    int tmp;
    CLR(bit);
    for(int i = 1; i <= n; i++){
        CIN >> tmp;
        update_bit(bit, n, tmp, tmp);
        p[i] = tmp - sum_bit(bit, tmp);
    }
    CLR(bit);
    for(int i = 1; i <= n; i++){
        CIN >> tmp;
        update_bit(bit, n, tmp, tmp);
        q[i] = tmp - sum_bit(bit, tmp);
    }
    for(int i = n - 1; i >= 1; i--){
        p[i] += q[i];
        p[i - 1] += p[i]/(n - i);
        p[i] = p[i]%(n - i);
    }
    CLR(bit);
    for(int i = 1; i <= n; i++){
        /*TODO */
    }
    return 0;
}



