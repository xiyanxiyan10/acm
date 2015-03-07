/**
 * @brief Codeforces Round #294 (Div. 2) d
 * @file d.cpp
 * @author mianma
 * @created 2015/03/02 11:56
 * @edited  2015/03/02 11:56
 * @type dp
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a))
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

//#define DEBUG 1

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
#define MAXC 26

typedef long long int ll;

ll char_val[MAXC];          /*record the val of each char*/
map<ll, ll> dp[MAXC];

string str;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    for(int i= 0; i < 26; i++)
        CIN >> char_val[i];

    CIN >> str;
    
    ll curr_val = 0, ans = 0;

    for(int i = 0; i < str.size(); i++){
            int ch = (unsigned char)str[i] - 'a';
            
            ans += dp[ch][curr_val];

            curr_val += char_val[ch];
            dp[ch][curr_val]++;
    }
    COUT << ans << endl;
    return 0;
}



