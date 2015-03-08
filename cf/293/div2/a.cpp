/**
 * @brief Codeforces Round #293 (Div. 2) a
 * @file a.cpp
 * @author mianma
 * @created 2015/03/08 22:39
 * @edited  2015/03/08 22£º39
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

#define MAXN 110
string a, b;
bool ans = true;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    CIN >> a >> b;
    int lft = 1;
    for(int i = a.size() - 1 ; i >= 0; i--){
            int ch = (int)a[i] + lft;
            if(ch > 'z'){
                a[i] = 'a';
                lft= 1;
            }else{
                a[i] = ch;
                break;
            }
    }
    ans = (a == b ?  false : true);
    COUT << (ans ? a : "No such string") << "\n";
    return 0;
}



