#include <stdio.h>
#include <string.h>

#define MAXN 110



char s[MAXN], t[MAXN];
int a, b, c;

int solve()
{
     if(1 != sscanf(s, "%d", &c)) return -1;

     sprintf(t, "%d", c);

     if(0 != strcmp(s, t))   return -1;

     return ( (c >= a && c <=b )? 0 : -1);
}


int main()
{
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out","w", stdout);
#endif
    
    while(gets(s)){
        scanf("%d%d", &a, &b);
        getchar();
        printf("%s\n", solve() ? "NO" : "YES");
    }
    return 0;
}
