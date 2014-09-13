#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned long long int ll;

int main(void)
{
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w",  stdout);
    printf("Output\n");
#endif
    int cases;
    ll n;
    ll idx;
    int val;
    scanf("%d", &cases);
    while(cases--){
        scanf("%lld", &n);
        for(idx = 1; idx <= n; idx++){
            scanf("%d", &val);
            if(1 != val)
                break;  /*break at first 1*/
        }
        idx = idx > n ? n : idx;
#ifdef DEBUG
        fprintf(stderr, "idx = %lld\n", idx);
#endif
        if(idx & (1ll))
                puts("Yes");
        else
                puts("No");
    }
    return 0;
}




