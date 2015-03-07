/* @brief  二分查找模板
    * @file base.h
    * @author sorcerer
    * @CreatedTime 2014/10/14
    * @LastChanged 2014/10/14
    *
    */
#include <stdio.h>
/***
 * @brief 二分查找下界
 * @param[in] a 数组
 * @param[in] x start pos
 * @param[in] y end   pos
 * @note 查找递增数组从左到右第一个大于或等于v的元素的位置,数组有效范围[x,y)
 */
int bsearch(int *a, int x, int y, int v)
{
    int m;
    while(x < y){
            m = x + ((y - x) >> 1);
            if(a[m] >= v)
                    y = m;
            else
                    x = m + 1;
    } 
    return x;
}

int main(){
        int a[5] = { 1, 2, 3, 3, 4, };
        int b[5] = { 5, 6, 6, 7, 8, };
        int c[5] = { 3, 3, 3, 6, 7, };
        printf("%d\n", bsearch(a, 0, 5, 3));
        printf("%d\n", bsearch(b, 0, 5, 9));
        printf("%d\n", bsearch(c, 0, 5, 2));
        return 0;
}

