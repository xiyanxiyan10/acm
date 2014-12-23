/**
 * @brief live archive 3635
 * @file 3635.cpp
 * @author mianma
 * @created 2014/12/23 16:11
 * @edited  2014/12/23 16:11
 * @type binart_search
 * @note
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <iomanip>

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

#define MAXN    10000
#define MAXF    10000
#define MAXR    10000

const double pi = acos(-1.0);

int n, cases, f;
double record[MAXN + 1];

bool check_area(const double &area){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += floor(record[i]/area);
    return sum >= f + 1;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> cases;
    while(cases--){
        CIN >> n >> f;
        double  r;
        double max_area = -1.0;
        for(int i = 0; i < n; i++){
            CIN >> r;
            record[i] =  pi*r*r;
            max_area = max(max_area, record[i]);
        }
        double lft = 0;
        double rht = max_area;
        double mid;
        while(rht - lft > 1e-5){
            mid = (rht - lft)/2 + lft;
            if(check_area(mid))
                lft = mid;
            else 
                rht = mid;
        }
        COUT << fixed << setprecision(4) << lft << "\n";
    }
    return 0;
}



