/**
 * @brief Codeforces Round #286 (Div. 2) a
 * @file a.cpp
 * @author mianma
 * @created 2014/01/19 09:30
 * @edited  2014/01/19 09:30
 * @type brute
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>

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

int m, n, pos;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> m >> n;
    int flag = 0x1;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int pos = flag ? n : 1; 
            COUT << ( (!(i&0x1) && j != pos) ? "." : "#");
        }
        if(!(i&0x1))
            flag ^= 0x1;
        COUT << "\n";
    }
    return 0;
}



