/*
 * @brief bayan_2015 c
 * @file c.c
 * @author xiyan
 * @CreatedTime 2014/11/04
 * @LastChanged 2014/11/04
 * @note
 *      dfs and brute questions
 *
 */


#include <stdio.h>

#define MAXN 1000

#define CLR(vec) memset(vec, 0, sizeof(vec))

bool table[MAXN][MAXN];         /*1. altered 0. not*/

int area;                       /*area brush covered*/
int row, col;                   /*brush size*/
int row1, row2, col1, col2;     /*brush pos*/  
int m, n;                       /*frame size*/

int check_valid(int row1, int row2, int col1, int col2){ 
    
    int i, j;

    if(row1 < 0 || row2 >= m || col1 < 0|| col2 >= n)
                return -1;
    for(i = row1; i < row2; i++)
        for(j = col1; j < col2; j++)
                if(!table[i][j])
                        return -1;
    return 0;
}

int check_right(int row1, int row2, int col1, int col2){
    int i, j;
    for(i = col2 + 1; i < n; i++)
        for(j = row1; j <= row2; j++)
                if(table[i][j])
                        return 1;

    return 0;
}

int check_down(int row1, int row2, int col1, int col2){
    int i, j;
    for(i = row2 + 1; i < m; i++)
        for(j = col1; j <= col2; j++)
                if(table[i][j])
                        return 1;
    return 0;
}



int dfs(int row1, int row2, int col1, int col2, int left){
    int rht_status;
    int down_status;

    if(!left){
            return 0;
    }

    rht_status = check_right(row1, row2, col1, col2);
    down_status = check_down(row1, row2, col1, col2);

    if(!(rht_status ^ down_status))
            return -1;
    if(rht_status){
            col1 += col;
            col2 += col;
    }else{
            row1 += row;
            row2 += row;
    }

    if( check_valid(row1, row2, col1, col2) < 0) 
            return -1;

    left-= area;
    return dfs(row1, row2, col1, col2, left);
}


int main()
{
    int start_find;
    int tot_alters;
    int i, j;
    char tmp;
    scanf("%d%d", &m, &n);
    
    start_find = 0;
    tot_alters = 0;
    int start_row;
    int start_col;
    int row, col;
    int row1, row2, col1, col2;

    for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                    scanf("%c", &tmp);
                    if(tmp == 'X'){
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
                   
            }
    }

    for(row = 1; row < m; row++){
            if( check_valid(row1, row2, col1, col2) < 0)
                    break;
        for(col = 1; col < m; col++){
            row1 = start_row;
            row2 = start_row + row - 1;
            col1 = start_col;
            col2 = start_col + col - 1;
            
            if( check_valid(row1, row2, col1, col2) < 0)
                    break;

            area = row * col;
            
            if(tot_alters%area)
                    continue;

            if( 0 == dfs(row1, row2, col1, col2, tot_alters)){
                printf("%d\n", area);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}




