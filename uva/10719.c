/*
 * @brief code for uva
 * @file 10719.c
 * @author xiyan
 * @CreatedTime 2014/10/31
 * @LastChanged 2014/10/31
 * @TODO wait to test
 */

#include <stdio.h>
#include <string.h>

#define MAXN 10010

typedef long long int ll;


ll org[MAXN], ans[MAXN];

#define CLR(vec) memset(vec, 0, sizeof(vec))

int main()
{
    int i;
    int k;
    int cnt;
    char ch;
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w",  stdout);
    printf("Output\n");
#endif
    while(EOF != scanf("%d", &k)){
        cnt = 0;
        CLR(org);
        CLR(ans);
        while( scanf("%lld%c", &org[cnt++], &ch) == 2 && ch != '\n');
    
        for(i = 0; i < cnt; i++)
            ans[i + 1] = org[i] + ans[i]*k;

        printf("q(x):");
        for(i = 1; i < cnt; i++)
            printf(" %lld", ans[i]);
    
        printf("\nr = %lld\n\n", ans[cnt]);
     
    }
    return 0;
}



