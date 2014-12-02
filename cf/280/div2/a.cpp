/**
 * @brief Codeforces Round #280 (Div. 2) a
 * @file a.cpp
 * @author mianma
 * @created 2014/12/02 10:43
 * @edited  2014/12/02 10:43
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

int n;          /*tot cubes*/
int tot;        /*curr floor tot cubes*/
int base;       /*base*/
int floor;      /*curr floor*/

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    floor = tot = base = 0;
    CIN >> n;
    do{
        floor++;
        base += floor;
        tot  +=  base;
    }while(tot <= n);

    COUT << (--floor) << "\n";
    return 0;
}



