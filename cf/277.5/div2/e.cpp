/**
 * @brief Codeforces Round #277.5 (Div. 2) e
 * @file e.cpp
 * @author 面码
 * @created 2014/11/24 11:51
 * @edited  2014/11/24 11:51
 * @type dp
 * @TODO wr
 * @note 
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

#define MAXN 1010
#define MAXD 1<<MAXN

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

using namespace std;

struct path_item{               /*point info*/
    int    distance;
    int    picture;
};

struct dp_item{                 /*item used for dp*/
    double frust;   
    int    picture;    
};

struct dp_item   dp[MAXN]; 
struct path_item path[1 << MAXD];

int n;
int l;

int main()
{
#ifdef DEBUG
    freopen("./in",  "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d", &n, &l);
    CLR(dp);
    CLR(path);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &path[i].distance, &path[i].picture);
    for(int len = 1; len <= n; len++){
        for(int idx = 0; idx < (1 << n); idx++){
                int old_idx = (idx & ~1); 
                if(old_idx&0x1){
                        dp[item]
                }else{
                        dp[idx] = dp[old_idx];
                }
                
        }
    }
    return 0;
}
