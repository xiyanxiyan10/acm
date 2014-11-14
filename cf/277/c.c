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
#define abs(a)     ((a) > 0   ? (a) : (0 - a))

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

#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif

    scanf("%d%d%s", &n, &p, str);
    midl = n >> 1;
    midr = n&0x1? midl : midr + 1;

    if(p == midl || p == midr){ /*pos in mid, so left half is the same with right half*/
        dir = 0;                /*default left*/
    }else{
        dir > midr ? 1: 0;      
    }
    
    lft = str;
    rht = str + n - 1;
    idx = str + p - 1;          /*p start from 1*/

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
                updown_mv += max(abs(*lft - *rht), abs(MAXC - abs(*lft - *rht)));
        }
        lft++;
        rht--;
    }
    printf("%d\b", (lft_max < rht_max ? (lft_max << 1) + rht_max : (rht_max << 1) + lft_max) + updown_mv);
    return 0;
}

