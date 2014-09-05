#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define CLR(vec) memset(vec, 0, sizeof(vec))
#define MAXN 40

typedef unsigned long long int ll;

char buf[MAXN];

int main(void)
{
    int tot_case, curr_case;
    ll base, sum, num, ans;

#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w",  stdout);
    printf("Output\n");
#endif
    scanf("%d", &tot_case);
    curr_case = 1;
    while(curr_case <= tot_case){
            CLR(buf);
            scanf("%s", buf);
#ifdef DEBUG
            fprintf(stderr, "str == %s in case %d\n", buf, curr_case);
#endif
            if('\n' == buf[0])
                    continue;
                
            if(buf[0] == '-'){
                num = atoll(buf + 1);       
            }else{
                num = atoll(buf);
            }
#ifdef DEBUG
           fprintf(stderr, "num == %lld in case %d\n", num, curr_case);
#endif
            for(base = 1, sum = 1; num >  sum; base++, sum += base);

#ifdef DEBUG
           fprintf(stderr, "base == %lld\n", base);
#endif
            for(; (sum - num) & ((ll)0x1);  base++, sum += base);

            ans = base;
            
            printf("%lld\n", ans);
            if(curr_case != tot_case)
                  printf("\n");
            curr_case++;
    }
    return 0;
}




