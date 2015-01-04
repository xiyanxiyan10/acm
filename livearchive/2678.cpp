/**
 * @brief live archive 3678
 * @file 2678.cpp
 * @author mianma
 * @created 2015/1/4 14:59
 * @edited  2015/1/4 14:59
 * @type 
 * @note 
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
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

#define MAXN 100100

typedef long long int ll;

int n, s, ans;
ll record[MAXN];

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",   ios::in);
    COUT.open("./out", ios::out);
#endif
    while(CIN >> n >> s){
            CLR(record);
            for(int i = 1; i <= n; i++){
                int tmp;
                CIN >> tmp;
                record[i] = record[i - 1] + tmp;
            }
            ans = n + 1;
            int i = 1;
            for(int j = 1; j <= n; j++){
                if(record[j] - record[i - 1] < s )
                    continue;
                while(record[j] - record[i - 1] >= s)
                    ++i;
                ans = min(ans, j - i + 2);
            }
            COUT << (ans == n + 1 ? 0  : ans) << "\n";
    }
    return 0;
}



