/**
 * @brief Codeforces Round #282 (Div. 2) 3401
 * @file 3401.cpp
 * @author mianma
 * @created 2014/12/16 16:35
 * @edited  2014/12/16 16:35
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
#define REP(i, n) for(i = 0; i < (n); i++)

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

#define MAXN  12

char pos[MAXN][MAXN][MAXN];         /*mark if this pos exist*/
char view[6][MAXN][MAXN];           /*record color for this pos*/
int n;

char read_color(){
    char ch;
    while(CIN){
        CIN >> ch;
        if( (ch >= 'A' && ch <= 'Z' )|| '.' == ch)
                return ch;
    }
}

int main(void){
    int i, j, k;
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    while(scanf("%d", &n) && n){
        REP(i, n)
            REP(j , 6)
                REP(k , n)
                        view[j][i][k] = read_color();
    
        CLR(pos);                   /*mark all sube cube exists*/
        int done = 0;
        while(0 == done){
            /*TODO find ans*/
                   
        
        
        
        }

        /*TODO output answer*/
    }

    return 0;
}



