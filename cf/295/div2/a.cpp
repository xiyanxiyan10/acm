/**
 * @brief Codeforces Round #294 (Div. 2) a
 * @file a.cpp
 * @author mianma
 * @created 2015/02/28 21:34
 * @edited  2015/02/28 21:34
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

#define MAXN 26

int n;
int table[MAXN];
string str;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    CIN >> n;
    CIN >> str;
    for(int i = 0; i < str.size(); i++){
        int ch;    
        if( 'a' <= str[i] && str[i] <= 'z')
            ch = str[i] - 'a';
        else
            ch = str[i] - 'A';

        table[ch]++;
    }
    int check = 1;
    for(int i = 0; i < MAXN; i++){
        if(!table[i]){
            check = 0;
            break;
        }
    }
    COUT << (check ? "YES" : "NO" ) << "\n";
    return 0;
}



