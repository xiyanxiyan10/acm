/**
 * @brief uva 11078
 * @file 11078
 * @author mianma
 * @created 2014/12/23 16:40
 * @edited  2014/12/23 16:40
 * @type 
 * @note
 */

#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cassert>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 100000
#define MAXV 150000

int T, n;
int record[MAXN + 10];
int table[MAXN + 10];

/*fast read IO*/
int read_int(){
    int neg = 0;
    int ch = getchar();
    while(!isdigit(ch) && '-' != ch)
        ch = getchar();
    if('-' == ch){
        ch = getchar();
        neg = 1;
    }
    int x = 0;
    while(isdigit(ch)){
        x  = x*10 + ch - '0';
        ch = getchar();
    }
    return ( neg ? 0 - x : x );
}

/*fast write IO*/
int write_int(int x){
    int neg = 0;
    static char buf[MAXV + 10];
    int n = 0;
    if(x < 0){
        neg = 1;
        x = abs(x);
    }
    while(x){
        buf[n++] = x%10 + '0';
        x       /= 10;
    }
    if(neg)
        putchar('-');
    for(int i = n -1 ; i >= 0; i--)
        putchar(buf[i]);
}

int main(void){
    int maxval, tmp;
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        maxval = -MAXV - 10;
        for(int i = 1; i <= n; i++){
                record[i] = maxval;
                table[i] = read_int();
                maxval = max(maxval, table[i]);
        }
        maxval = -MAXV - 10;
        for(int i = 2; i <= n; i++)
                maxval = max(maxval, record[i] - table[i]);
        write_int(maxval);
        putchar('\n');
    }
    return 0;
}



