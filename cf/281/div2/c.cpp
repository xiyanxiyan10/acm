/**
 * @brief Codeforces Round #281 (Div. 2) c
 * @file c.cpp
 * @author 面码
 * @created 2014/12/05 11:54
 * @edited  2014/12/05 15:36
 * @type  brute
 * @think Consider brute at first
 *
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 200010
#define MAXV 200000000

typedef long long int ll;

int n_vec[MAXN], m_vec[MAXN];
int tmp, m, n;
ll max_val, max_tmp, max_a, max_b, max_n, max_m;

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    for(int i = 0; i < n; ++i)  CIN >> n_vec[i];
    CIN >> m;
    for(int i = 0; i < m; ++i)  CIN >> m_vec[i];

    sort(n_vec, n_vec + n);
    sort(m_vec, m_vec + m);
    
    max_a = 2*n;
    max_b = 2*m;
    max_val = max_a - max_b;

    for(int i = 0, j = 0; i < m; ++i){
        if(i > 0 && n_vec[i] == n_vec[i - 1])   continue;
        while(j < m && m_vec[j] < n_vec[i])     ++j;
        max_n = 2*1LL*i + 3*1LL*(n - i);
        max_m = 2*1LL*j + 3*1LL*(m - j);
        max_tmp = max_n - max_m;
        if( max_tmp > max_val || max_tmp == max_val && max_n > max_a){
            max_a = max_n;
            max_b = max_m;
            max_val = max_tmp;
        }
    }
    COUT << max_a << ":" << max_b << "\n";
    return 0;
}



