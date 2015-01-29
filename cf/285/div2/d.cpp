/**
 * @brief Codeforces Round #285 (Div. 2) d
 * @file d.cpp
 * @author mianma
 * @created 2015/01/27 18:18
 * @edited  2015/01/27 18:18
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

static inline void build_bit(int *vec, int *bit, int size){
    for(int i = 1; i <= size; i++){
            bit[i] = vec[i];
            for(int j = i - 1; j > i - low_bit(i); j-= low_bit(j))
                bit[i] += bit[j];
    }
}

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

/* O(lgn) search, O(lgn) update , O(n) memory cost*/

static inline void debug_vec(int *vec, int size){
    for(int i = 0; i < size; i++)
        COUT << vec[i] << " ";
    COUT << "\n";
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

    /* Cantor expansion */
    CIN >> n;
    int tmp;
    CLR(bit);
    for(int i = 1; i <= n; i++){
        CIN >> tmp;
        tmp++;
        update_bit(bit, n, tmp, 1);
        p[i] = tmp - sum_bit(bit, tmp);
    }

#ifdef DEBUG
    COUT << "vec for p\n";
    debug_vec(p + 1, n);
#endif

    CLR(bit);
    for(int i = 1; i <= n; i++){
        CIN >> tmp;
        tmp++;
        update_bit(bit, n, tmp, 1);
        q[i] = tmp - sum_bit(bit, tmp);
    }

#ifdef DEBUG
    COUT << "vec for q\n";
    debug_vec(q + 1, n);
#endif

    for(int i = n; i >= 1; i--){
        p[i] += q[i];
        p[i - 1] += p[i]/(n - i + 1);
        p[i] = p[i]%(n - i + 1);
    }
    
#ifdef DEBUG
    COUT << "vec for p + q\n";
    debug_vec(p + 1, n);
    COUT << endl;
#endif
    

    /*record nums not used*/
    CLR(bit);
    for(int i = 1; i <= n; i++)
        update_bit(bit, n, i, 1);

    /* reverse Cantor expansion */
    for(int i = 1; i <= n; i++){
        int val = p[i] + 1;
        int lft = val;
        int rht = n;

        /*binary search*/
        while(lft < rht){
            int mid = ( (rht - lft)>> 1) + lft;
            int top = sum_bit(bit, mid);
            if(top < val){
                lft = mid + 1;   
            }else{
                rht = mid;
            }
        }
        q[i] = lft;
        update_bit(bit, n, lft, -1);
    }

    for(int i = 1; i <= n; i++)
        COUT << q[i] - 1 << (i == n ? "\n" : " ");
    return 0;
}

