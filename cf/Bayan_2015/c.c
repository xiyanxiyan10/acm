/*
 * @brief bayan_2015 c
 * @file c.c
 * @author xiyan
 * @CreatedTime 2014/11/04
 * @LastChanged 2014/11/06
 * @note
 *      type: dfs, brute, greedy, dp
 *
 * @TODO TL
 *
 */


#include <stdio.h>

#define MAXN 1100

int table[MAXN][MAXN];          /*1. altered 0. not*/
int sum[MAXN][MAXN];            /*used for dp*/
char buf[MAXN];                 /*quick IO*/

int area;                       /*area brush covered*/
int row, col;                   /*brush size*/
int row1, row2, col1, col2;     /*brush pos*/  
int m, n;                       /*frame size*/
int start_row, start_col;       /*start pos*/

#define CLR(vec) memset(vec, 0, sizeof(vec))

#define CHECK_MV(x, y, d, r)    ( (x + d <= m) && (y + r <= n) && (sum[x + d][ y + r] - sum[x + d][y] - sum[x][y + r] + sum[x][y] == (d)*(r)))

int check_valid(int row1, int row2, int col1, int col2){ 
    
    int i, j;
    if(row2 >= m || col2 >= n)
                return -1;

    for(i = row1; i <= row2; i++)
        for(j = col1; j <= col2; j++)
                if(!table[i][j])
                        return -1;
    return 0;
}


int dfs(int row1, int col1, int left){
    int col_move;
    int row_move;

    while(1){

        if(!left){
            return 0;
        }
        
        for(col_move = 0;  CHECK_MV(row1, col1 , row, col_move +  col); col_move++)
                    ;
#ifdef DEBUG
    printf("###############################\n");
#endif
        for(row_move = 0;  CHECK_MV(row1, col1, row_move + row, col); row_move++)
                    ;

        row_move--;
        col_move--;

#ifdef DEBUG
    printf("row1:%d, col1:%d, col_move:%d, row_move:%d, left:%d\n", row1, col1, col_move, row_move, left);
#endif

        if( !col_move &&!row_move)
            return -1;
        if( col_move && row_move)
            return -1;

        if(col_move){
            col1 += col_move;
            left -= row*col_move;
        }else{
            row1 += row_move;
            left -= col*row_move;
        }
    }
}


int main()
{
    int start_find = 0;
    int tot_alters = 0;
    int i, j;
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif

    scanf("%d%d", &m, &n);
    getchar();

    for(i = 0; i < m; i++){
            gets(buf);
            for(j = 0; j < n; j++){
                    if(buf[j] == 'X'){
                            table[i][j] = 1;
                            if(start_find == 0){
                                    start_find = 1;
                                    start_row = i;
                                    start_col = j;
                            }
                            tot_alters++;
                    }else{
                            table[i][j] = 0;
                    }
                    sum[i + 1][j + 1] =  sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (table[i][j]? 1 : 0); /*dp here*/ 
            }
    }
#ifdef DEBUG
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++)
            printf("%c", table[i][j] ? 'X': '.');
        printf("\n");
    }
    for(i = 0; i < m + 1; i++){
        for(j = 0; j < n + 1; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }
#endif
    row1 = start_row;
    row2 = start_row;
    col1 = start_col;
    col2 = start_col;
#ifdef  DEBUG
    printf("start_row: %d; start_col:%d\n", start_row, start_col);
#endif
    for(area = 1; area <= tot_alters; area++)
        for(row = 1; row <= m - start_row; row++){
                if(area%row)
                        continue;

                col = area/row;

                row2 = row1 + row -1;
                col2 = col1 + col -1;

            if(check_valid(row1, row2, col1, col2)< 0)
                            continue;
#ifdef DEBUG
    printf("row:%d , col:%d, row1:%d, row2:%d, col1:%d, col2:%d->>>>\n", row, col, row1, row2, col1, col2);
#endif

            if( 0 == dfs(start_row, start_col, tot_alters - area)){
                printf("%d\n", area);
                return 0;
            }
        }
    printf("-1\n");
    return 0;
}




