/**
 * @brief Codeforces Round #282 (Div. 2) a
 * @file a.cpp
 * @author mianma
 * @created 2014/12/15 9:55
 * @edited  2014/12/15 9:55
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

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

const int table[] = {1, 6, 1, 2, 2, 3, 1, 4, 0, 1};
string str;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> str;
    COUT << (table[str[0] - '0'] + 1)* (table[str[1] - '0']+ 1) << "\n"; 
    return 0;
}



