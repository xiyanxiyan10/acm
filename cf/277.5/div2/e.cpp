/**
 * @brief Codeforces Round #277.5 (Div. 2) e
 * @file e.cpp
 * @author 面码
 * @created 2014/11/24 11:51
 * @edited  2014/11/24 11:51
 * @type dp
 * @TODO test
 * @note 
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

#define MAXN 1010

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
    int    prev;                /*get prev one, stop when prev is 0*/
};

struct dp_item   dp[MAXN]; 
struct path_item path[MAXN];

int ans;
int n;
int l;

void print_path(int idx){
    if(0 != dp[idx].prev)
        print_path(dp[idx].prev);
    printf("%d\n", idx);
}

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
    for(int i = 1; i <= n; i++){
        double curr_val;
        double curr_frust;
        int    curr_picture;
        double min_frust;
        int    min_picture;
        int    min_idx = -1;
        double min_val = 10000000000.0;
        for(int j = 0; j < i; j++){
                curr_frust = dp[j].frust +  sqrt((double)abs(path[i].distance - path[j].distance - l));
                curr_picture = dp[j].picture + path[i].picture;
                curr_val = curr_frust/curr_picture;
                if(curr_val < min_val){
                    min_val = curr_val;
                    min_idx = j;
                    min_frust = curr_frust;
                    min_picture = curr_picture;
                }   
        }
        dp[i].frust = min_frust;
        dp[i].picture = min_picture;
        dp[i].prev = min_idx < 0 ? 0 : min_idx;
#ifdef DEBUG
        printf("idx %d\n", i);
        printf("frust %lf\n",  dp[i].frust);
        printf("picture %d\n", dp[i].picture);
        printf("prev %d\n",    dp[i].prev);
        printf("val %lf\n",    dp[i].frust/dp[i].picture);
#endif
    }
    print_path(n);
    return 0;
}
