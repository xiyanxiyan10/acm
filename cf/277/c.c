/**
 * @brief Codeforces Round #277 (Div. 2) c
 * @file c.c
 * @author 面码
 * @created 2014/11/14 13:39
 * @edited  2014/11/14 13:39
 * @type greedy
 * @TODO test
 *
 */
#include <stdio.h>

#define MAXN 100010
#define MAXC 26

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))

int n, p;
char str[MAXN];
int lft_mv, rht_mv, updown_mv, lft_max, rht_max;

int main(void){
    char *lft;        /*ptr to left*/
    char *rht;        /*ptr to right*/
    char *idx;        /*ptr to start pos*/
    char *curr;       /*ptr to char with to convert*/
    int  dir;         /*convert str in right half or left half?*/
    int midl, midr;
    int ans;            

#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif

    scanf("%d%d%s", &n, &p, str);

    p--;                        /*p start from 0 now*/
    midr = n >> 1;

    if(n&0x1){
        dir = p > midr ? 1: 0;
    }else{
        midl = midr - 1;
        dir = p >= midr ? 1 : 0;
    }

#ifdef DEBUG
    printf("pos at %s\n", dir ? "right" : "left");
#endif
    
    lft = str;
    rht = str + n - 1;
    idx = str + p;                  

    lft_max = -1;
    rht_max = -1;
    updown_mv = 0;
    
    while(lft <= rht){          /*analysis str*/
        if(*lft != *rht){
                curr = dir ? rht : lft;
                if(curr >= idx){
                    rht_mv = curr - idx;
                    rht_max = max(rht_max, rht_mv);
                }
                if(curr <= idx){
                    lft_mv = idx - curr;
                    lft_max = max(lft_max, lft_mv);
                }
                updown_mv += min(abs(*lft - *rht), abs(MAXC - abs(*lft - *rht)));
        }
#ifdef DEBUG
        printf("rht_max = %d, lft_max = %d, updown_max = %d, lft = %p, rht = %p, idx = %p\n", rht_max, lft_max, updown_mv, lft, rht, idx);
#endif
        lft++;
        rht--;
    }
    do{         /**analysis all cases here*/
        if(-1 == lft_max && -1 == rht_max){
                    ans = 0;
                    break;
        }

        if(-1 == lft_max){
            ans = rht_max + updown_mv;
            break;
        }

        if(-1 == rht_max){
            ans = lft_max + updown_mv;
            break;
        }
        
        ans = (lft_max < rht_max ? (lft_max << 1) +  rht_max : (rht_max << 1) + lft_max) + updown_mv;
    
    }while(0);
    
    printf("%d\n", ans); 
            
    return 0;
}

