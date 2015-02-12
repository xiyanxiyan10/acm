/**
 * @brief Rockethon 2015 a
 * @file a.cpp
 * @author mianma
 * @created 2015/02/12 09:30
 * @edited  2015/02/12 09:30
 * @type 
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

int n1, n2, k1, k2;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n1 >> n2 >> k1 >> k2;
    COUT << ( n1 - n2 > 0 ? "First" : "Second" ) << endl;
    return 0;
}



