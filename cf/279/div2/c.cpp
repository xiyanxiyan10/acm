/**
 * @brief Codeforces Round #279 (Div. 2) c
 * @file c.cpp
 * @author mianma
 * @created 2014/11/28 17:06
 * @edited  2014/12/1  18:23
 * @type math
 * @note
 */
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 1000010

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

int lft_record[MAXN];    /*division pos record*/
int rht_record[MAXN];    /*division pos record*/

int i;
int lft, rht;
int n;
int base;
string str;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif

    CIN >> str;
    CIN >> lft >> rht;

    n = str.size();

    /*check str*/
    if('0' == str[0] || n < 2){
        COUT << "NO\n";
        return 0;
    }

    lft_record[0] = 0;
    for(int i = 1; i < n; i++)
        lft_record[i] = ((str[i - 1] - '1' + 1) + lft_record[i - 1] * 10)%lft;
    
    rht_record[n + 1] = 0;
    base = 1;
    /*(x1 + x2)%y = (x1%y + x2%y)%y,  x%y = x%y%y%y%y*/
    for( int i = n; i > 1; i--){
        rht_record[i] = ((str[i - 1] - '1' + 1)*base + rht_record[i + 1])%rht;
        base = (10 * base)%rht; 
    }

    for(int i = 1; i < n; i++){
        if(lft_record[i] || rht_record[i + 1]||'0' == str[i])
                continue;

        COUT << "YES\n";
        for(int idx = 1; idx <= i; idx++)
                COUT << str[idx - 1];
        COUT << "\n";
        for(int idx = i + 1; idx <= n; idx++)
                COUT << str[idx - 1];
        COUT << "\n";
        return 0;
    }
    COUT << "NO\n";
    return 0;
}



