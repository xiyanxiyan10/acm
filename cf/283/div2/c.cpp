/**
 * @brief Codeforces Round #283 (Div. 2) c
 * @file c.cpp
 * @author mianma
 * @created 2014/12/22 13:38
 * @edited  2014/12/22 13:38
 * @type greedy
 * @time cost time O(m*n)
 * @mem  cost mem  2*MAXN^2 + 2*MAXN
 * @note
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

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
int record[MAXN][MAXN];     /*record row status */
int status1[MAXN];          /*curr row's substring is the same with the prev row*/
int status2[MAXN];              
int n, m;
int ans = 0;
int *curr = status1;
int *old  = status2;

int main(void){
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    	scanf("%s", table[i]);
    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            record[i][j] = table[i][j] - table[i - 1][j];

    for(int col = 0; col < m; col++){
        int fail = 0;
        for(int row = 1; row < n; row++){
            /*substring is the same with the prev row*/
            if(0 == old[row]){
                if(record[row][col] > 0)   
                    curr[row] = 1;
                else if(record[row][col] < 0){
                        fail = 1;
                        break;
                }else
                    curr[row] = 0;
            }else
                    curr[row] = 1;
        }
        if(!fail){
#ifdef DEBUG
        printf("col %d insert\n", col);
        printf("bmp new:\n");
        for(int j = 1; j < n; j++)
            printf("%d ", curr[j]);
        printf("\n");
#endif
            int * tmp = curr;
            curr = old;
            old = tmp;
            ++ans;
        }
    }
    printf("%d\n", m - ans);
    return 0;
}



