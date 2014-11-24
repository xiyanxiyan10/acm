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
    scanf("%d", &n);
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &path[i].distance, &path[i].picture);
    for(int i = 1; i <= n; i++){
        double max_val = 0.0;
        double curr_val;
        double frust;
        int picture;
        int    max_idx;
        for(int j = 0; j < i; j++){
                frust = dp[j].frust +  sqrt((double)abs(path[i].distance - path[j].distance));
                picture = dp[j].picture + path[j].picture;
                curr_val = frust/picture;
                if(curr_val > max_val){
                    max_val = curr_val;
                    max_idx = j;
                }   
                dp[i].frust = frust;
                dp[i].picture = picture;
                dp[i].prev = j;
        }
    }
    print_path(n);
    return 0;
}
