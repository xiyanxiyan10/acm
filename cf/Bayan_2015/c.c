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
int row_pos, col_pos;	                /*brush pos*/  
int m, n;                       /*frame size*/
int start_row, start_col;       /*start pos*/
int max_row, max_col;     
int cnt, tot;


#define CLR(vec) memset(vec, 0, sizeof(vec))
#define min(x,y) ((x) < (y) ? (x) : (y))

#define CHECK_MV(x, y, d, r)    ( (x + d <= m) && (y + r <= n) && \
		(sum[x + d][ y + r] - sum[x + d][y] - sum[x][y + r] + sum[x][y] == (d)*(r)))


int dfs(int row_pos, int col_pos){
    int col_move;
    int row_move;
    int i;

    if(0 == CHECK_MV(row_pos, col_pos, row, col)){
    	return -1;	
    }

    cnt = row * col;

    while(1){

        if(tot == cnt){
            return 0;
        }
        
	col_move = 0;
	for(i = 1; CHECK_MV(row_pos, col_pos , row, i +  col); i++){
		col_move++;
	}
#ifdef DEBUG
    printf("--------------------------------------------------\n");
#endif
    	row_move = 0;
        for(i = 1;  CHECK_MV(row_pos, col_pos, i + row, col); i++){
         	row_move++;           
	}

#ifdef DEBUG
    printf("row_pos:%d, col_pos:%d, col_move:%d, row_move:%d, tot:%d\n", row_pos, col_pos, col_move, row_move, cnt);
#endif

        if( !col_move && !row_move)
            return -1;
        if( col_move && row_move)
            return -1;

        if(col_move){
            col_pos += col_move;
            cnt += row*col_move;
        }else{
            row_pos += row_move;
            cnt += col*row_move;
        }
    }
}


int main()
{
    int start_find = 0;
    int i, j;
    tot = 0;
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
                            tot++;
                    }else{
                            table[i][j] = 0;
                    }
		    /*dp here*/ 
                    sum[i + 1][j + 1] =  sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (table[i][j]? 1 : 0); 
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

    for(max_row = 0 ; (start_row + max_row <= m) && table[start_row + max_row][start_col]; max_row++)
                                ;
    for(max_col = 0 ; (start_col + max_col <= n) && table[start_row][start_col + max_col]; max_col++) 
                                ;

#ifdef  DEBUG
    printf("start_row: %d; start_col:%d, max_row: %d; max_col: %d\n", start_row, start_col, max_row, max_col);
#endif

    area = 0x7fffffff;

    for(col = max_col, row = 1; row <= max_row; row++)
        if( 0 == dfs(start_row, start_col))
                    area = min(area, row*col);

    for(row = max_row, col = 1; col <= max_col; col++)
            if( 0 == dfs(start_row, start_col))
                    area = min(area, row*col);

    if(area == 0x7fffffff)
            printf("-1\n");
    else
            printf("%d\n", area);
    return 0;
}




