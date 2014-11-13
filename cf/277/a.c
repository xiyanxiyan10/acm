/**
 * @brief Codeforces Round #277 (Div. 2) a
 * @author xiyan
 * @created 2014/11/13 11:23
 * @edited  2014/11/13 11:24
 * @type math 
 * 
 *
 */

#include <stdio.h>

long long int a;

int main()
{
    scanf("%I64d", &a);
    printf("%I64d\n", (a >> 1) - ( a &0x1 ? a : 0));
    return 0;
}