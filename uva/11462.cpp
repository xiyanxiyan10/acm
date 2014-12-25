/**
 * @brief uva 11462
 * @file 11462.cpp
 * @author mianma
 * @created 2014/12/16 16:07
 * @edited  2014/12/16 16:07
 * @type sort
 * @note
 */
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXV   100 

/*radix sort' counter */
int c[MAXV + 10];

/*fast read IO*/
int read_int(){
    int ch = getchar();
    while(!isdigit(ch))
        ch = getchar();
    int x = 0;
    while(isdigit(ch)){
        x  = x*10 + ch - '0';
        ch = getchar();
    }
    return x;
}

/*fast write IO*/
int write_int(int x){
    static char buf[8];
    int n = 0;
    while(x){
        buf[n++] = x%10 + '0';
        x       /= 10;
    }
    for(int i = n -1 ; i >= 0; i--)
        putchar(buf[i]);
}

int main(void){
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    int n, tmp;
    while(~scanf("%d", &n) && n){
        CLR(c);
        for(int i = 0; i < n; i++)
                ++c[read_int()];
        int tot = 0;
        for(int i = 1; i <= MAXV; i++){
            while(c[i]){
                write_int(i);
                --c[i];
                ++tot;
                printf("%c", tot == n ? '\n': ' ');
            }
        }
    }
    return 0;
}



