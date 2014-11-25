/**
 * @brief Codeforces Round #278 (Div. 2) c
 * @file c.c
 * @author 面码
 * @created 2014/11/25 14:15
 * @edited  2014/11/25 14:15
 * @type brute
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
    for(atkC = 0; atkC <= 200; atkC++)
            for(defC = 0; defC <= 200; defC++){
                decY = atkM - (defY + defC);
                decM = (atkY + atkC) - defM;
    
                if(decM <= 0)           /*can't kill monster*/
                    continue;

                if(decY > 0){
                    round =  hpM/decM + (hpM%decM ? 1: 0);
                    hpC = hpY - decY*round;
                    if(hpC <= 0)
                        hpC = abs(hpC) + 1;
                    else
                        hpC = 0;
                }else{
                        hpC = 0;            /*need not buy hp*/
                }
                curr_cost = hp*hpC + atk*atkC + def*defC;
                min_cost = min(curr_cost, min_cost);
            }
    printf("%d\n", min_cost);
    return 0;
}
