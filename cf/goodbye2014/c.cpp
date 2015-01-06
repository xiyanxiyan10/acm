/**
 * @brief good bye 2014 c
 * @file c.cpp
 * @author mianma
 * @created 2014/01/06  16:42
 * @edited  2014/01/06  16:42
 * @type game
 * @note 
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

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

#define MAXN 1010

typedef long long int ll;

int table[MAXN];    /*value table*/
int mv[MAXN];       /*move table*/
int vec[MAXN];      /*build stack*/
int cnt;
int ans;

int main(void){
    int n, m, tmp;
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n >> m;
    for(int i = 1; i <= n; i++)
        CIN >> table[i];
    for(int i = 1; i <= m; i++){
        int newone = 1;
        CIN >> tmp;
        mv[i] = tmp;
        for(int j = 0; j < cnt; j++){
            if( tmp == vec[j]){
                newone = 0;
                break;
            }
        }  
        if(newone)
            vec[cnt++] = tmp;
    }
    for(int i = 1; i <= m; i++){
        int idx = mv[i];
        for(int j = 0; j < cnt; j++){
                if(vec[j] == idx){

                        for(int k = j - 1; k >= 0; k--){

                            ans += table[vec[k]];

                            vec[k + 1] = vec[k];
                        }
                        vec[0] = idx;
                        break;
                }
        }
    }
    COUT << ans << "\n";
    return 0;
}



