/**
 * @brief Codeforces Round #284 (Div. 2) a
 * @file a.cpp
 * @author mianma
 * @created 2014/12/26 11:51
 * @edited  2014/12/26 11:51
 * @type brute
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

#define MAXN 50
#define MAXV 1e5

int n, x;
int p1, p2, t1, t2, tot1, tot2;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> p1 >> p2 >> t1 >> t2;
    tot1 = max(3*p1/10, p1 - (p1/250)*t1);
    tot2 = max(3*p2/10, p2 - (p2/250)*t1);
    if(tot1 == tot2){
        COUT << "Tie\n"; 
    }else if(tot1 > tot2){
        COUT << "Misha\n";
    }else{
        COUT <<"Vasya\n";
    }
    return 0;
}



