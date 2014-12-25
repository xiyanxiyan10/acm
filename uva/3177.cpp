/**
 * @brief uva 3177
 * @file 3177.cpp
 * @author mianma
 * @created 2014/12/25 15:20
 * @edited  2014/12/25 15:20
 * @type game binary_search
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

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

#define MAXN        100010
#define MAXV        100010

int n;
int table[MAXN], lft[MAXN], rht[MAXN];

/*check if it is possible*/
bool check(int v){
    int r1 = table[0];
    lft[0] = r1;
    rht[0] = 0;
    for(int i = 1; i < n; i++){
        if(i & 1){     
            lft[i] = min(table[i], r1 - lft[i - 1]);
            rht[i] = table[i] - lft[i];
        }else{  
            rht[i] = min(table[i], v - r1 - rht[i - 1]);     
            lft[i] = table[i] - rht[i];
        }
    }
    return (0 == lft[n - 1]);
}

int main(void){
    //ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    int l, r;
    while(CIN >> n && n){
        for(int i = 0; i < n; ++i)
            CIN >> table[i];
        if(1 == n){
            COUT << table[0] << "\n";
            continue;
        }
        table[n] = table[0];
        l = 0,  r = 0;
        for(int i = 0; i < n; i++)
            l = max(l, table[i] + table[i + 1]);
        if(n & 1){
            for(int i = 0; i < n; i++)
                r = max(r, table[i]*3);
            while(l < r){
              int m = (r + l)/2;
                if(check(m))
                    r = m;
                else
                    l = m + 1;
            }
        }
        COUT << l << "\n";
    }
    return 0;
}



