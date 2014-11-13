/**
 * @brief Codeforces Round #277 (Div. 2) b
 * @author 面码
 * @created 2014/11/13 14:01
 * @edited  2014/11/13 14:01
 * @type greedy
 * @TODO less space and time cost with bitmap 
 * 
 *
 */

#include <stdio.h>

#define MAXN 110

//int a[MAXN][MAXN];
int b[MAXN][MAXN];      /*ans table*/
int c[MAXN][MAXN];      /*mark at least one 0*/

int tmp;
int row, col;

int main()
{
    int i, j, m, n, find;
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d", &row, &col);
    for(i = 1; i<= row; i++)
        for(j = 1; j<= col; j++){
                scanf("%d", &tmp);
                if(tmp){
                   c[i][j] = 1;
                }else{
                    /*zero mark as 1*/
                    for(m = 1; m <= row; m++)
                            b[m][j] = 1;
                    for(n = 1; n <= col; n++)
                            b[i][n] = 1;        
                }
        }

    for(i = 1; i <= row; i++)
        for(j = 1; j <= col; j++){
                if(c[i][j]){
                        find = 0;
                        for(m = 1; m <= row; m++)      
                                if(!b[m][j]){
                                    find = 1;
                                    break;
                                }
                        if(find)
                            continue;

                        for(n = 1; n <= col; n++)
                                if(!b[i][n]){
                                    find = 1;
                                    break;
                                }
                        if(find)
                            continue;
                        
                        goto fail;
                }       
        }

//success:
    printf("YES\n");
    for(i = 1; i<= row; i++){
        for(j = 1; j <= col; j++){
                printf("%d%c", 1 == b[i][j] ? 0 : 1, col == j ? '\n' : ' ');
        }
    }

    return 0;

fail:
    printf("NO\n");
    return 0;
}