/**
 * @brief Codeforces Round #294 (Div. 2) c
 * @file c.cpp
 * @author mianma
 * @created 2015/02/28 15:17
 * @edited  2015/02/28 15:17
 * @type greedy
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

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

#define MAXN 100100


int m, n;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    CIN >> m >> n;
    int cnt = 0;
    while((m >= 1 && n >= 2)||(m >= 2 && n >= 1)){
        if(m >= n){
            m -= 2;
            n -= 1;
        }else{
            m -= 1;
            n -= 2;
        }
        cnt++;
    }
    COUT << cnt << endl;
    return 0;
}



