/*
 * @brief 线状数组模板
 * @file array_tree.h
 * @author xiyan
 * @CreatedTime 2015/02/28
 * @LastChanged 2015/02/28
 */

#include <iostream>

/*api for binary index tree*/
static inline int low_bit(int i){
    return ( i & ( - i));
}

static inline void build_bit(int *vec, int *bit, int size){
    for(int i = 1; i <= size; i++){
            bit[i] = vec[i];
            for(int j = i - 1; j > i - low_bit(i); j-= low_bit(j))
                bit[i] += bit[j];
    }
}

static inline int sum_bit(int *bit, int k){
    int ans = 0;
    for(int i = k; i > 0; i -= low_bit(i))
        ans += bit[i];
    return ans;
}

static inline void update_bit(int *bit, int size, int i, int val){
    for(int j = i; j <= size; j += low_bit(j))
            bit[j] += val;
    
}

/* O(lgn) search, O(lgn) update , O(n) memory cost*/


