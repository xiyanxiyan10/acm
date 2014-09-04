#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define CLR(vec) memset(vec, 0, sizeof(vec))
#define MAXN 40

char buf[MAXN];

int main(void)
{
    int tot_case, curr_case;
    long long int  num;
    long long int ans;
    double tmp;

#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w",  stdout);
#endif
    scanf("%d", &tot_case);
    curr_case = 0;
    while(curr_case <= tot_case){
            CLR(buf);
            scanf("%s", buf);
#ifdef DEBUG
            fprintf(stderr, "str == %s in case %d\n", buf, curr_case);
#endif

            if(buf[0] == '-'){
                num = 0 - atoll(buf + 1);       
            }else{
                num = atoll(buf);
            }
#ifdef DEBUG
           fprintf(stderr, "num == %lld in case %d\n", num, curr_case);
#endif
            do{
                tmp = (0.0 + sqrt(9.0 + 4.0*(4.0 + 2.0*num)) + 3.0)/2.0;
                ans = (long long int)floor(tmp + 0.5);
                if(ans == tmp)
                        break;

                tmp = (0.0 - sqrt(9.0 + 4.0*(4.0 + 2.0*num)) + 3.0)/2.0;
                ans = (long long int)floor(tmp + 0.5);
                if(ans == tmp)
                        break;
            }while(0);
            printf("%lld\n", ans);
            curr_case++;
            if(curr_case != tot_case)
                printf("\n");

    }
    return 0;
}




