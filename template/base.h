/*
 * @brief  基础模板
 * @file base.h
 * @author xiyan
 * @CreatedTime 2014/09/04
 * @LastChanged 2014/10/02
 * @note 功能列表
 *       1.设置bit位置
 *       2.检查数据是否为2的幂
 *       3.交换两数
 *       4.统计某一数值中1的个数
 *       5.浮点数转整形
 *       6.求大于等于x的最小2^n
 *
 */
#ifndef  BASE_H_
#define  BASE_H_

#ifdef __cplusplus 
extern "C" { 
#endif 

#include "stdlib.h"  
#include "string.h"
#include "stdio.h"
#include "math.h"

#define INIT_TAT(TAT)              TAT = (0L)                                           /*STATUS INIT*/
#define SET_TAT(TAT, FLAG)         TAT = ((TAT)|(FLAG))                                 /*STATUS SET*/
#define CLEAN_TAT(TAT, FLAG)       TAT = ((TAT)&(~(FLAG)))                              /*STATUS CLEAN*/
#define CHECK_TAT(TAT, FLAG)       ((FLAG) == ((TAT)&(FLAG)))                           /*STATUS CHECK*/

/**
 * @brief 判断一个数是否为2的倍数
 * @param[in] x 被判断的数
 * @return 1 是， 0 否
 *
 */
#define check2(x) ( x & (x - 1) ? 1 : 0)


/* @brief 亦或交换
 * @param[in] a 指向被交换元素
 * @param[in] b 指向被交换元素
 * @note 指针不能指向同一个数
 */
static inline void swap1(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;   
}

/* @brief 增补损益交换
 * @param[in] a 指向被交换元素
 * @param[in] b 指向被交换元素
 * @note 指针不能指向同一个数
 */
static inline void swap2(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;   
}

/* @brief 普通交换
 * @param[in] a 指向被交换元素
 * @param[in] b 指向被交换元素
 *
 */
static inline void swap3(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a  = *b;
    *b  = tmp;   
}


/**
 * @brief 统计1的个数
 * @param[in] x欲统计的数
 */
static inline int count1(int x)
{
    int ret = 0;
    while(x){
        x &= (x - 1);
        ret++;
    }
    return ret;
}



/***
 * @brief get the min int y which is bigger than x
 * @param[in] x double param
 * @return int
 */
#define doubleToInt1(x) ((int)(floor(((double)x) - (1e-9)) + 1)) 


/**
 * @brief If we make sure x it a double val convert from int val y
 *  This can help us to find the val y
 * @param[in] x double param
 * @return int
 */
#define doubleTint2(x) ((int)(floor(((double)x) + (0.5)))


/*
 * @brief 大于等于x的最小2^n
 * @param[in] 指定数字
 * @return 2^n >= x 
 */
static int pow1(int nrows)
{
    unsigned i;
    nrows -= 1;
    for(i=1; i<sizeof(nrows) * 8; i <<= 1)
        nrows = nrows | (nrows >> i);
    nrows += 1;
 
    return nrows;
}


#ifdef __cplusplus 
}
#endif 

#endif
