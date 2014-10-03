/*
 * @brief  排列计算模板模板
 * @file perm.c
 * @author xiyanxiyan10
 * @CreatedTime 2014/10/03
 * @LastChanged 2014/10/03
 */


#include <stdio.h>
#include "base.h"

/**
 * @ brief 对输入集合进行全排列
 * @ param[in] array 输入集合的头指针
 * @ param[in] spos 输入集合中首个元素idx
 * @ param[in] epos 输入集合的最后一个idx
 * @ note 无输入检测
 *       cost mem  : 0
 *       cost time : n!
 */
void _perm(int *array, const int spos, const int epos)
{
    int i;
    if(spos == epos){
            for(i = 0; i <= epos; i++)
                    printf("%d ", array[i]);
            printf("\n");
    }else{
        for(i = spos; i <= epos; i++){
            swap3(array + i, array + spos);   
            _perm(array,    spos + 1, epos);
            swap3(array + i, array + spos);
        }
    }
}


int main()
{

    return 0;
}
