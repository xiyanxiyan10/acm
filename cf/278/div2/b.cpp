/**
 * @brief Codeforces Round #278 (Div. 2) a
 * @file a.c
 * @author 面码
 * @created 2014/11/24 17:52
 * @edited  2014/11/18 17:52
 * @type brute
 * @TODO debug
 * @note 
 *          k >= 0;
 *          x1 = k
 *          x2 + x3 = 4k;
 *          x4 = 3k
 *          x1 <= x2 <= x3 <= x4
 *
 */
#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 2000

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))

int tmp;
int n;
int table[MAXN + 50];
int anstable[MAXN + 50];

int main()
{
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
            table[tmp]++;
    }
    if(!n){
        printf("YES\n");
        printf("1\n1\n3\n3\n");
    }
    int a, b, c, d;
    for(a = 0; a <= 500; a++)
        for( d = 3*a, b = 0; b <= 4*a; b++){
                c = a + d - b;
                anstable[a]++;
                anstable[b]++;
                anstable[c]++;
                anstable[d]++;
                
                int cost = 0;
                if(anstable[a] >= table[a]){
                    cost += table[a];
                    anstable[a] -= table[a];
                }

                if(anstable[b] >= table[b]){
                    cost += table[b];
                    anstable[b] -= table[b];
                }

                if(anstable[c] >= table[c]){
                    cost += table[c];
                    anstable[c] -= table[c];
                }

                if(anstable[d] >= table[d]){
                    cost += table[d];
                    anstable[d] -= table[d];
                }
                
                if(cost == n){
                    printf("YES\n");
                    while(anstable[a]){
                        printf("%d\n", a);
                        anstable[a]--;
                    }

                    while(anstable[b]){
                        printf("%d\n", b);
                        anstable[b]--;
                    }

                    while(anstable[c]){
                        printf("%d\n", c);
                        anstable[c]--;
                    }

                    while(anstable[c]){
                        printf("%d\n", c);
                        anstable[c]--;
                    }
                    return 0;
                }else{
                    anstable[a] = 0;
                    anstable[b] = 0;
                    anstable[c] = 0;
                    anstable[d] = 0;
                }
            }
            printf("NO\n");
    return 0;
}
