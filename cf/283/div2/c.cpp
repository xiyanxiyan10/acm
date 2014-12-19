/**
 * @brief Codeforces Round #283 (Div. 2) b
 * @file b.cpp
 * @author mianma
 * @created 2014/12/19 18:59
 * @edited  2014/12/19 18:59
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

#define MAXN 110

char table[MAXN][MAXN];     /*store input string*/
int n, m;
int ans = MAXN;

/**
 * @brute all possible answer
 * @param[in] used how many col selected 
 * @param[in] free col group start   
 *
 */
void brute(int used, int start){
    if(m == start)
        ans = min(ans, n - used);
    for(int i = start; i < m; i++){
        int j;
        char ch = table[0][i];
        for(j = 1; j < n; j++){         
            if(table[j][i] < ch)
                    break;
            else
                ch = table[j][i];
        }
        if(j != n)
            continue;
        brute(used, i + 1);
    }
}

int main(void){
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", table[i]);
    brute(0, 0);
    return 0;
}



