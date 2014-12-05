/**
 * @brief Codeforces Round #281 (Div. 2) b
 * @file b.cpp
 * @author 面码
 * @created 2014/12/05 11:54
 * @edited  2014/12/05 11:54
 * @type  binary_search
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

vector<int> n_vec, m_vec;
int tmp, m, n;
int max_pos = -1;
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

long long  int search_points(vector<int> & vec, int key){
    int mid;
    int lft = 0;
    int rht = vec.size();
    while( lft < rht){
            mid  = ((rht - lft)>> 1) + lft;
            if(vec[mid] <= key)
                    lft = mid + 1;
            else
                    rht = mid;
    }
    return ( 2 * (ll )rht + 3 * ( vec.size() - (ll)rht ));
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    for(int i = 0; i < n; i++){
        CIN >> tmp;
        max_pos = max(tmp, max_pos);
        n_vec.push_back(tmp);
    }
    sort(n_vec.begin(), n_vec.end());

    CIN >> m;
    for(int i = 0; i < m; i++){
        CIN >> tmp;
        max_pos = max(tmp, max_pos);
        m_vec.push_back(tmp);
    }
    sort(m_vec.begin(), m_vec.end());
    
    max_n = search_points(n_vec, max_pos);
    max_m = search_points(m_vec, max_pos);
    max_val = max_n - max_m;
    max_a = max_n;
    max_b = max_m;
    
    for(int i = 0; i <= max_pos; i++){
            max_n = search_points(n_vec, i);
            max_m = search_points(m_vec, i);
            max_tmp = max_n - max_m;
            if(max_tmp > max_val){
                max_a = max_n;
                max_b = max_m;
                max_val = max_tmp;
            }else if(max_tmp == max_val && max_n  > max_a){
                max_a = max_n;
                max_b = max_m;
                max_val = max_tmp;
            }else{
                ;
            }
    }
    COUT << max_a << ":" << max_b << "\n";
    return 0;
}



