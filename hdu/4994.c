#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned long long int ll;

#define CLR(vec) memset(vec, 0, sizoef(vec))

#define MAXN 1000

ll table[MAXN+ 10];

int main(void)
{
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w",  stdout);
    printf("Output\n");
#endif
    int cases, n, i;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &n);
        for( i = 0; i < n; i++){
                scanf("%lld", &table[i]);
        }
        for(i = 0; i < n - 1; i++){
                if( 1 != table[i])
                        break;
        }
        if(i & 0x1)
                puts("No");
        else
                puts("Yes");
    }
    return 0;
}




