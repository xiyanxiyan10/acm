/*
 * @brief  排序计算模板模板
 * @file perm.c
 * @author xiyanxiyan10
 * @CreatedTime 2014/05/04
 * @LastChanged 2014/10/03
 */


#include <stdlib.h>
#include <string.h>
#include "base.h"



static int submerge_sort(int *a, int p, int q);
static void BuildHeap(int *a,int size); 
static void MaxHeapify(int *a, int i, int size);
static int subquick_sort(int *a, int p, int q);
int subradix_sort(int *key, int *data, int *count, int *tmp, int size, int k);

/**
 * @breif 选择排序
 * @param[in] a 被排序数组的指针
 * @param[in] len 被排序的集合总元素个数
 * @note
 *      cost mem : 0
 *      cost time：n^2 
 *      稳定性   : 不稳定
 *
 *
 */
void selection_sort(int *a, const int size)
{
    int tmp, i, j;
    for(i = 0; i < size - 1; i++)
    {
        int find = -1;
        j = i + 1, tmp = a[i];
        while(j < size){
            if(tmp > a[j]){
                 tmp = a[j];
                 find = j;    
            }
            ++j;
        }    
        if(find != -1){   
	    swap1( &a[i], &a[find]);
        }
    }
}

/**
 * @breif 冒泡排序
 * @param[in] a 被排序数组的指针
 * @param[in] size 被排序的集合总元素个数
 * @note
 *      cost mem : 0
 *      cost time：n^2 
 *      稳定性   : 稳定
 *
 */
void bubble_sort(int *a, const int size)
{
    int i, j;
    for(i = 0; i < size; i++){
        for( j = 0; j < size - i - 1; j++){
            if(a[j] > a[j+1]){
                swap1(&a[j], &a[j+1]);
            }
        }
    }
}

/*
 * @brief 插入排序
 * @param[in] a 被排序数组的指针
 * @param[in] size 被排序的集合总元素个数
 * @note 
 *      cost mem : 0
 *      cost time: n^2
 *      稳定性   : 稳定
 *
 */ 
void insert_sort(int *a, const int size)
{
    int tmp, i, j;
    if(size < 2)
        return;
    for(i = 1; i < size; i++){
            tmp = a[i];        
            for(j = i - 1; j >= 0; j--){
                if(a[j] < tmp){    
                    a[j + 1] = tmp;
                    break;
                }
                a[j + 1] = a[j];
            }
    }
}


/**
 * @brief 归并排序
 * @param[in] a 指向被排序集合
 * @param[in] p 被排序的集合首个元素
 * @param[in] q 被排序的集合最后的元素
 * @note 
 *      costmem  : 1~n 
 *      cost time: nlgn
 *      稳定性   : 稳定
 *
 */
void _merge_sort(int *a, int p, int q)
{
    int mid;
    if(p < q){
        mid = (p + q)/2;    
        _merge_sort(a, p, mid);
        _merge_sort(a, mid + 1, q);
        submerge_sort(a, p, q);
    }
}


int submerge_sort(int *a, int p, int q)
{
    int *tmp, mid, size, left, right, index;
    if(p == q)
        return 0;
            mid = (p + q)/2;
    size  = q - p + 1;
    tmp   = (int *)malloc((size)*sizeof(int));
    left  = p; 
    right = mid + 1;
    index = 0;
    while(left != mid + 1 && right != q + 1){
        if(a[left] < a[right]){
            tmp[index++] =  a[left++];
        }else{
            tmp[index++] =  a[right++];
        }
    } 

    while(left  != mid + 1)
        tmp[index++] =  a[left++];
    while(right != q + 1)
        tmp[index++] =  a[right++];

    index = 0;
    while(index != size)
        a[p++] = tmp[index++];
    free(tmp);
return 0;    
}

/**
 * @brief 堆排序
 * @param[in] a 被排序数组的指针
 * @param[in] size 被排序的集合总元素个数
 * @note 
 *      cost mem : 0
 *      cost time: nlgn
 *      稳定性   : 不稳定
 *
 */
void heap_sort(int *a, int size)
{
    int i;
    BuildHeap(a, size);
    for(i = size; i > 1; i--){
        swap1( &a[0], &a[i - 1]);
        MaxHeapify(a, 0, i - 1); 
    }
}

void MaxHeapify(int *a, int i, int size)            
{
    int largest, rchild, lchild, circle = 1;
    while(circle){
        lchild = 2*i+1, rchild = 2*i+2;
        largest = i;
    
        if(lchild < size && a[lchild] > a[largest])
            largest = lchild;

        if(rchild < size && a[rchild] > a[largest])
            largest = rchild;

        if(largest != i){
            swap1(&a[largest], &a[i]);
            i = largest;
        }else{
             circle = 0;
        }
    }
}

void BuildHeap(int *a,int size)    
{
    int i;
    for(i = size - 1; i >= 0; i--){
        MaxHeapify(a, i, size); 
    }    
} 


/** 
 * @brief 快速排序
 * @param [in] 指向被排序集合的首地址
 * @param[in] p 被排序的集合首个元素
 * @param[in] q 被排序的集合最后的元素
 * @note 
 *       cost mem  : 0
 *       cost time : nlgn
 *       稳定性    : 不稳定
 */
void _quick_sort(int *a, int p, int r)
{
    int q;
    if(p < r){
        q = subquick_sort(a, p, r);
        _quick_sort(a, p, q - 1);
        _quick_sort(a, q + 1, r);
    }
}

int subquick_sort(int *a, int p, int q)
{
    int i, j, x;
        i = p - 1; 
        j = i + 1;
        x = a[q];
    for(; j < q; j++){
        if( a[j] < x){
            ++i;
            swap3(&a[i], &a[j]);
        }
    }
    ++i;
    swap3(&a[i], &a[j]);
return i;        
}


/**
 * @brief 计数排序
 * @param[in] a 被排序数组的指针
 * @param[in] size 被排序的集合总元素个数
 * @param[in] k    被排序元素的大小范围
 * @note 
 *      cost mem  : k*sizeof(int) 
 *      cost time : O(n+k)
 *      稳定性    : 不稳定 
 */ 

int count_sort(int *a, int size, int k)
{
    int *count, i, j;
    count = (int *)malloc(k * sizeof(int));
    for(i = 0; i != size; i++){
        ++count[a[i]];
    }
    j = 0, i = 0;
    while(j != k){
        while(count[j]--){
            a[i++] = j;
        }
        ++j;
    }
    free(count);
}


/**
 * @brief 基数排序
 * @param[in] a 指向带排序的数据集合
 * @param[in] size 被排序的元素个数
 * @note  
 *      cost mem : 16*sizeof(int)
 *      cost time : O(n+k)
 *      稳定性    : 稳定 
 */
void radix_sort(int *a, int size)
{
    int *key, circle, i, tmp, *atmp, *count, base = 0;

    /*统一申请，防止反复申请开销过大*/
    key    =  (int*)malloc(size *sizeof(int));
    atmp   =  (int *)malloc(size * sizeof(int));
    count  =  (int *)malloc(32 * sizeof(int));
    
    while(1)
    {
        circle = 0;
        for(i = 0; i < size; i++){
                tmp = a[i] >> base;
                tmp &= 0x1f;
                key[i] = tmp;
                if(tmp != 0 )
                    circle = 1;
        }
        if(circle == 0)
            break;
        memset(count, 0, 32);
        subradix_sort(key, a, count, atmp, size, 32);
        base += 4;
    }
    free(key);
    free(count);
    free(atmp);
}

int subradix_sort(int *key, int *data, int *count, int *tmp, int size, int k)
{
    int i;
    for(i = 0; i < size; i++)
    {
        ++count[key[i]];
    }
    for(i = 1; i < k; i++ )
    {
        count[i] += count[i - 1];
    }
    for(i = size - 1; i >= 0; i--)
    {
        tmp[--count[key[i]]] = data[i];
    }
    for(i = 0; i < size; i++)
    {
        data[i] = tmp[i];
    }
return 0;
}


/**
 * @brief 希尔排序
 * @param[in] a 指向带排序的数据集合
 * @param[in] size 被排序的元素个数
 * @note  
 *      cost mem  : 0
 *      cost time : O(n ~ n^2)
 *      稳定性    : 不稳定 
 */
void shell_sort(int *a, int size)
{
    int step, j, k, tmp;
    for(step = size >> 1; step; step >>= 1){
        for(j = step ; j < size; j++){
            tmp = a[j];
            for( k = j - step; k >= 0 && tmp < a[k]; k -= step){
                        a[k + step ] = a[k];
                    
            }
            a[k + step] = tmp;
        }
    }
}

/**
 * @brief 鸡尾酒排序法
 * @param[in] a
 * @param[in] size 被排序的元素个数
 * @note  
 *      cost mem  : 0
 *      cost time : O(n ~ n^2)
 *      稳定性    : 稳定 
 */
void sour_sort(int *a, int size){
        int i, j, pos;
        i = 0; j = size - 1;
        while( i < j){
               for(pos = i; pos < j; pos++)
                    if(a[pos] > a[pos + 1])
                            swap1( &a[pos] , &a[pos + 1]);
               j--;
               for(pos = j; pos > i; pos--){
                    if(a[pos] < a[pos - 1])      
                            swap1( &a[pos] , &a[pos - 1]);
               }
               i++;
        }
}


/**
 * @brief 桶形排序
 * @param[in] a 指向待排序的集合
 * @param[in] size 被排序的元素个数
 * @param[in] bucket_num 桶的个数
 * @TODO Just as a demo
 * @note 
 *      cost mem size*sizeof(node) + sizeof(void *)*bucket_num
 *      cost time O(N)+O(M*(N/M)*log(N/M))=O(N+N*(logN-logM))=O(N+N*logN-N*logM)
 */
typedef struct nodes{
    int val;
    struct nodes *next;
}node;

int bucketSort(int *a, int size, int bucket_num)
{
    int i, index, count;
    node **store = (node **)malloc(bucket_num * sizeof(node*));
    for(i = 0; i < bucket_num; i++){
        store[i] = NULL;
    }
    for(i = 0; i < size; i++)
    {
        node *tmp = (node *)malloc(sizeof(node));
        tmp->val = a[i];    
        tmp->next = NULL;
        index = a[i]/10;
        node *p = store[index];
        if(p){
            node *q = NULL;
            while(tmp->val > p->val && p->next){
                q = p;
                p = p->next;
            }
            if(tmp->val <= p->val){
                if(store[index] == p){
                    tmp->next = p;
                    store[index] = tmp;
                }else{
                    q->next = tmp;
                    tmp->next = p;
                }                    
            }else{
                p->next = tmp; 
            }
        }else{
            store[index] = tmp;
        }
    }
    count = 0;
    for(i = 0; i < bucket_num; i++)
    {
        node *out = store[i];
        while(out){
            a[count++] = out->val;
            out = out->next;
        }

    }
    for(i = 0; i != bucket_num; i++){
        free(store[i]); 
    }
    free(store);
return 0;    
}



int main()
{

    return 0;
}
