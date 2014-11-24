/**
 *
 * @brief Codeforces Round #278 (Div. 2) a
 * @file a.c
 * @author mianma
 * @created 2014/11/24 17:52
 * @edited  2014/11/18 17:52
 * @type brute
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
int usetable[MAXN + 50];

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
	return 0;
    }
    int a, b, c, d;
    for(a = 0; a <= 500; a++)
        for( d = 3*a, b = 0; b <= 4*a; b++){
                c = a + d - b;

		if(a <= b && b <= c && c <=d)
			;
		else
			continue;

                anstable[a]++;
                anstable[b]++;
                anstable[c]++;
                anstable[d]++;
                int cnt;
                int cost = 0;
		int tot  = 0;
                if(!usetable[a] && anstable[a] >= table[a]){
			anstable[a] -= table[a];
			cost        += table[a];
			usetable[a] = 1;
		}

                if(!usetable[b] && anstable[b] >= table[b]){
                    	anstable[b] -= table[b];
			cost 	    += table[b];
			usetable[b] = 1;
                }


                if(!usetable[c] && anstable[c] >= table[c]){
                    	anstable[c] -= table[c];
			cost 	    += table[c];
			usetable[c] = 1;
		}

                if(!usetable[d] && anstable[d] >= table[d]){
                    	anstable[d] -= table[d];
			cost 	    += table[d];
			usetable[d] = 1;
		}
                  
                if(cost == n){
#ifdef DEBUG
		    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
#endif
		    //return 0;

                    printf("YES\n");
                    while(anstable[a]-- > 0)
                        printf("%d\n", a);

                    while(anstable[b]-- > 0)
                        printf("%d\n", b);
                    
                    while(anstable[c]-- > 0)
                        printf("%d\n", c);

                    while(anstable[d]-- > 0)
                        printf("%d\n", d);
                    
                    return 0;
                }else{
                    anstable[a] = 0;
                    anstable[b] = 0;
                    anstable[c] = 0;
                    anstable[d] = 0;

                    usetable[a] = 0;
                    usetable[b] = 0;
                    usetable[c] = 0;
                    usetable[d] = 0;
                }
            }
            printf("NO\n");
    return 0;
}



