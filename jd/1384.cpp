/**
 * @brief jiu du 1384
 * @file 1384.cpp
 * @author mianma
 * @created 2014/01/20 14:16
 * @edited  2014/01/20 14:16
 * @type binary search
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

#define MAXN 1100
int table[MAXN][MAXN];
int m, n, q;
 
int main()
{
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    while(CIN >> m >> n && m && n){
        CIN >> q;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                CIN >> table[i][j];
        int row = 1, col = n;
        int ans = 0;
        while(row <= m && col){
            if(table[row][col] == q){
                    ans = 1;
                    break;
            }else if (table[row][col] > q){
                    --col;   
            }else{
                    ++row;
            }
        }
        COUT << (ans ? "Yes" : "No") << "\n";
    }
    return 0;
}
