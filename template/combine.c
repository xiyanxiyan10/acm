/*
 * @brief  组合计算模板模板
 * @file combine.c
 * @author xiyanxiyan10
 * @CreatedTime 2014/10/03
 * @LastChanged 2014/10/03
 */


#include <stdio.h>
#include "base.h"



#define SET_POS(a, b)               SET_TAT  (a[b>>5], (1 << (b & 0x1f)))
#define CLEAN_POS(a, b)             CLEAN_TAT(a[b>>5], (1 << (b & 0x1f)))
#define CHECK_POS(a, b)             CHECK_TAT(a[b>>5], (1 << (b & 0x1f)))


static void _combine2(int *array, int *record, const int m, const int n, const int M);

/**
 * @ brief 输出对输入集合 m 选 n 的所有组合
 * @ param[in] array 输入集合的头指针
 * @ param[in] m 输入集合中欲选取的数字个数
 * @ param[in] n 输入集合的数字个数
 * @ note 无输入检测, 输入集合最少两个数
 *  5 选 3流程示意图如下
 * 1   1   1   0   0   //1,2,3     
 * 1   1   0   1   0   //1,2,4     
 * 1   0   1   1   0   //1,3,4     
 * 0   1   1   1   0   //2,3,4     
 * 1   1   0   0   1   //1,2,5     
 * 1   0   1   0   1   //1,3,5     
 * 0   1   1   0   1   //2,3,5     
 * 1   0   0   1   1   //1,4,5     
 * 0   1   0   1   1   //2,4,5     
 * 0   0   1   1   1   //3,4,5
 * @TODO 开销计算
 *
 */
void combine1(int *array, const int m, const int n)
{
    int i, pos;                       /*pos 用来存放1*/                    
    unsigned int *tarray;
    int status;                       /*三种状态转换, 0 初始状态, 1.已扫描到一 2. 在一状态中扫描到0*/                        
    
    tarray = (unsigned int *)malloc( ( (n >> 5) +\
     (n & 0x1f ? 1 : 0) )* sizeof( unsigned int));        /*计算需要的临时表大小*/
    memset(tarray, 0, n);
    for(i = 0; i < m; i++){
        SET_POS(tarray,     i);
        printf("%d ", array[i]);
    }
    printf("\n");
    while(1){
        status = 0;
        for(i = 0, pos = 0; i < n; i++){
                if(!CHECK_POS(tarray, i)){
                        if(1 == status){         /*找到 1, 0的组合*/
                                status = 2;  
                                SET_POS(tarray,     i);
                                CLEAN_POS(tarray,   (pos - 1));
                                break;
                        }
                }else{                          /*找到1*/
                        status = 1;
                        CLEAN_POS(tarray,     i);
                        SET_POS(tarray,     pos);
                        pos++;
                }
        }
        if(2 == status){
            for(i = 0; i < n; i++)
                    if(CHECK_POS(tarray, i))
                            printf("%d ", array[i]);
                    printf("\n");
        }else{
            break;
        }
    }
}

/**
 * @ brief 输出对输入集合 m 选 n 的所有组合
 * @ param[in] array 输入集合的头指针
 * @ param[in] m 输入集合中欲选取的数字个数
 * @ param[in] n 输入集合的数字个数
 * @ note 无输入检测, 输入集合最少两个数
 * @TODO 开销计算
 * 
 */
void combine2(int *array, const int m, const int n){
    int *tarray = (int *)malloc(m * sizeof(int));
    _combine2(array, tarray, m, n, m);
    free(tarray);
}


void _combine2(int *array, int *record, const int m, const int n, const int M){
    int i;
    for(i = n; i >= m; i--){
        record[m - 1] = i - 1;  
        if( m > 1){
                _combine2(array, record, m - 1, i - 1, M);
        }else{
                for(i = M - 1; i >= 0; i--)
                    printf("%d ", array[record[i]]);
                printf("\n") ;          
        }
    }
}


int main()
{

    return 0;
}
