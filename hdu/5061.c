/*
 * @brief hdu 5061
 * @file 5061.c
 * @author xiyan
 * @CreatedTime 2014/11/12
 * @LastChanged 2014/11/12
 * @note
 *      type: brute
 *
 */


#include <stdio.h>

int T, N;

static int palinedrome(int num);

int palinedrome(int num){
    int left, right;
    left = right = num;
    return 0;
}


int main()
{
    int maxnum, i, ans;
    scanf("%d", &T);
    while(T--){
        maxnum = 1;
        ans = 0;
        scanf("%n", &N);
        for(i = 0; i < N; i++)
                maxnum *= 10;
        for(i = 1; i <= maxnum; i++)
                if(palinedrome(i))
                        ans++;
    }
    return 0;
}
