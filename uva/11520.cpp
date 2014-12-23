/**
 * @brief uva 11520
 * @file 11520.cpp
 * @author mianma
 * @created 2014/12/23 16:11
 * @edited  2014/12/23 16:11
 * @type binart_search
 * @note
 */

#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN    10

int   record[MAXN + 5][MAXN + 5];
char  table[MAXN + 5][MAXN + 5];

int n, cases;
/*all neighbour pos*/
int dir[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
}; 

/*set char can't use*/
static inline void bmp_set(int *bmp, const char &c){
       *bmp |= (1 << (c  - 'A'));
}

/*search the min char could use*/
static inline int bmp_find(const int *bmp){
    for(int ch = 0 ; ch < 'A' - 'Z'; ch++){
        if(0 == (*bmp & (1 << (ch - 'A'))) )
                return ( ch + 'A');
    }
    return EOF;
}

/*mark all neighbour*/
static inline int update_neighbour(const int &i, const int &j){
    for(int k = 0; j < 4; k++){
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x >= n || x < 0 || y >= n || y < 0)
                    continue;
            bmp_set(&record[i][j], table[x][y]);
    }
}

int main(void){
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d", &cases);
    while(cases--){
        CLR(record);
        scanf("%d", n);
        for(int i = 0; i < n; i++)
            scanf("%s", table[i]);
        for(int i  = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                update_neighbour(i, j);
            }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if('.' != table[i][j])
                    continue;
                int ch = bmp_find(&record[i][j]);
                table[i][j] = ch;   
                update_neighbour(i, j);
            }
        /*TODO out*/
    }
    return 0;
}



