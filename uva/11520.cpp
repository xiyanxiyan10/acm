/**
 * @brief uva 11520
 * @file 11520.cpp
 * @author mianma
 * @created 2014/12/23 16:35
 * @edited  2014/12/23 16:35
 * @type 
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
static inline void bmp_set(int *bmp, const char &ch){
       *bmp |= (1 << (ch  - 'A'));
}

/*search the min char could use*/
static inline int bmp_find(const int *bmp){
    for(int ch = 'A' ; ch <= 'Z'; ch++){
        if(0 == (*bmp & (1 << (ch - 'A'))) )
                return ch;
    }
    return EOF;
}

/*mark all neighbour*/
static inline int char_find(const int &i, const int &j){
    int bmp = 0;
    for(int k = 0; k < 4; k++){
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x >= n || x < 0 || y >= n || y < 0)
                    continue;
            if('.' == table[x][y])
                    continue;
            bmp_set(&bmp, table[x][y]);
    }
    return bmp_find(&bmp);
}

int main(void){
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d", &cases);
    for(int idx = 1; idx <= cases; idx++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%s", table[i]);
        for(int i  = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if('.' == table[i][j])
                    table[i][j] = char_find(i, j);
            
        printf("Case %d:\n", idx);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                    printf("%c", table[i][j]);
            printf("\n");
        }
    }
    return 0;
}



