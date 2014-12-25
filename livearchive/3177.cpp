/**
 * @brief live archive 3177
 * @file 3177.cpp
 * @author mianma
 * @created 2014/12/25 11:46
 * @edited  2014/12/25 11:46
 * @type game
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
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

#define MAXN        100010
#define MAXV        100010
int n;

int table[MAXN], lft[MAXN], rht[MAXN];

/*check if it is possible*/
bool check(int v){
    int l, r;
    l = table[1], r = v - l; 
    lft[1] = v, rht[1] = 0;
    for(int i = 2; i <= n; i++){
        if(i&0x1){
            
        }else{
              
        
        }
    }
    return lft[n] == 0;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    int ans;
    int l, r;
    while(CIN >> n){
        for(int i = 1; i < n; i++)
            CIN >> table[i];
        table[n + 1] = table[1];
        for(int i = 1; i <= n; i++){
            l = max(l, table[i] + table[i+1]);
            r = max(r, table[i]*3);
        }
        if(n & 0x1){
            int m;
            while(l < r){
                m = (r - l)/2 + l;
                if(check(m))
                    r = m;
                else
                    l = m + 1;
            }
            ans = m;
        }else{
            ans = l;
        }
        COUT << ans << endl;
    }
    return 0;
}



