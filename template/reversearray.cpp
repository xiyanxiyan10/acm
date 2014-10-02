/*
 * @brief  旋转数组模板
 * @file reversearray.cpp
 * @author xiyanxiyan10
 * @CreatedTime 2014/10/02
 * @LastChanged 2014/10/02
 * @note
 * 该题目来自 http://ac.jobdu.com/problem.php?pid=1386 
 *  目前任然有数据未通过， 注意333123 为合法输入
 *  朴素可直接AC，但这里重点考察二分 
 */
 
#include <cstdio>

#define MAXSIZE 1000010
#define MAXVAL  10000010
 
int elementTots;
int elements[MAXSIZE];
 
int main()
{
    int ans;
    while( EOF != scanf("%d", &elementTots)){
        for(int currPos = 1; currPos <= elementTots; currPos++){
            scanf("%d", &elements[currPos]);
        }
        int lftPos = 1;
        int rhtPos = elementTots;
        if(elements[lftPos] < elements[rhtPos]|| 1 == elementTots){
                ans = elements[lftPos];
        }else{
            while(lftPos < rhtPos){
                if(1 == rhtPos - lftPos){
                    ans = elements[rhtPos];
                    break;
                }
                int midPos = lftPos + ( (rhtPos - lftPos) >> 1);
                    if(elements[midPos] >= elements[lftPos]){
                            lftPos = midPos;
                            continue;
                    }
                    if(elements[midPos] < elements[rhtPos]){
                            rhtPos = midPos;
                            continue;
                    }
                    if(elements[midPos] == elements[rhtPos]){
                            rhtPos = midPos - 1;
                    }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
