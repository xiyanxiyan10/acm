/**
 * @brief Codeforces Round #281 (Div. 2) d
 * @file d.cpp
 * @author 面码
 * @created 2014/12/05 18:19
 * @edited  2014/12/05 18:19
 * @type  game
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

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

int n;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    if(n & 0x1){
        COUT << "black\n";           
    }else{
        COUT << "white\n";
        COUT << "1 2\n";
    }
    return 0;
}



