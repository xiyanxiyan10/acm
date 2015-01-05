/**
 * @brief good bye 2014 a
 * @file a.cpp
 * @author mianma
 * @created 2014/01/05 17:45
 * @edited  2014/01/05 17:45
 * @type 
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

int n, t;
int ans;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    int offset;
    int curr = 1;
    int ans = 0;
    CIN >> n >> t;
    for(int i = 1; i <= n; i++){
        CIN >> offset;
        if(i == curr)
            curr += offset;
        if(curr > t){
            break;
        }
        else if(curr == t){
            ans = 1;
            break;
        }else
            ;
    }
    COUT << (ans ? "YES" : "NO" )<< "\n";
    return 0;
}



