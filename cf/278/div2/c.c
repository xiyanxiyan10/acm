/**
 * @brief Codeforces Round #278 (Div. 2) c
 * @file c.c
 * @author 面码
 * @created 2014/11/25 9:57
 * @edited  2014/11/25 9:57
 * @type brute
 * @TODO wr in test11
 *
 */
#include <stdio.h>

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))

int hpY, atkY, defY;
int hpM, atkM, defM;
int hp,  atk,  def;
int hpC, atkC, defC;

int main()
{
    int min_cost, curr_cost;
    int decY, decM;
    int round;
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d%d", &hpY, &atkY, &defY);  
    scanf("%d%d%d", &hpM, &atkM, &defM);  
    scanf("%d%d%d", &hp,  &atk,  &def);  
    min_cost = 0x7fffffff;
    for(hpC = 0; hpC <= 100; hpC++)
        for(atkC = 0; atkC <= 100; atkC++)
            for(defC = 0; defC <= 100; defC++){
                decY = atkM - (defY + defC);
                decM = (atkY + atkC) - defM;
                if(decM <= 0)           /*can't kill monster*/
                    continue;

                if(decY > 0){
                    round =  hpM/decM + (hpM%decM ? 1: 0);
                    if(hpY  + hpC - decY*round <= 0)
                            continue;
                }
                curr_cost = hp*hpC + atk*atkC + def*defC;
                min_cost = min(curr_cost, min_cost);
            }
    printf("%d\n", min_cost);
    return 0;
}
