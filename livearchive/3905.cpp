/**
 * @brief live archive 3905
 * @file 3905.cpp
 * @author mianma
 * @created 2014/12/24 15:03
 * @edited  2014/12/24 15:03
 * @type 
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
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

int w, h, cases;
int n;
int x, y, a, b;

struct event{
#define LFT_EVENT 0
#define RHT_EVENT 1
    int type;
    double pos;
};

class meteor{
public:
    vector<struct event> vec;
    void clean(){
        vec.clear();
    }
    int insert(int &x, int &y, int &a, int &b){
    }
};

#define INF (1e-9)

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",   ios::in);
    COUT.open("./out", ios::out);
#endif
    meteor solve;
    CIN >> cases;
    while(cases--){
        CIN >> n;
        for(int i = 0; i < n; i++){
            CIN >> x >> y >> a >> b;
            solve.insert(x, y, a, b);
        }
    }
    return 0;
}



