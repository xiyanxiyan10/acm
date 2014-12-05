/**
 * @brief Codeforces Round #281 (Div. 2) b
 * @file b.cpp
 * @author 面码
 * @created 2014/12/04 18:40
 * @edited  2014/12/05 9:37
 * @type  implementation
 *
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 200010

struct player{
    const char *name; 
    int points[MAXN];
    long long int tot;
    int cnt;
}players[2] = {
    {
        .name = "first"
    },
    {
        .name = "second"  
    }
};

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

int n, tmp;
struct player * player_last;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    for(int i = 0; i < n; i++){
        CIN >> tmp;
        player_last  = tmp > 0 ? &players[0] : &players[1];
        tmp = abs(tmp);
        player_last->tot += tmp;
        player_last->points[player_last->cnt++] = tmp;
    }

    struct player *lft, *rht;
    lft = &players[0];
    rht = &players[1];

    if(lft->tot < rht->tot){
        COUT << rht->name << "\n";
        return 0;
    }else if(lft->tot > rht->tot){
        COUT << lft->name << "\n";
        return 0;
    }else{
        ;
    }
    
    int i;
    for(i = 0; i < max(lft->cnt, rht->cnt); i++){
            if(lft->points[i] != rht->points[i])
                    break;
    }

    if(lft->points[i] > rht->points[i]){
        COUT << lft->name << "\n";
        return 0;
    }

    if(lft->points[i] < rht->points[i]){
        COUT << rht->name << "\n";
        return 0;
    }
    
    COUT << player_last->name << "\n";
    return 0;
}



