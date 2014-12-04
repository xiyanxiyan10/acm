/**
 * @brief Codeforces Round #281 (Div. 2) b
 * @file b.cpp
 * @author 面码
 * @created 2014/12/04 18:40
 * @edited  2014/12/04 18:40
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

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    for(int i = 0; i < n; i++){
        CIN >> tmp;
        struct player * player_curr  = tmp > 0 ? &players[0] : &players[1];
        tmp = abs(tmp);
        player_curr->points[player_curr->cnt++] = tmp;
        player_curr->tot + tmp;
    }
    if(players[0].tot <  players[1].tot){
        COUT << players[1].name << "\n";
        return 0;
    }else if(players[0].tot > players[1].tot){
        COUT << players[0].name << "\n";
        return 0;
    }
    
    int i;
    for(i = 0; i < max(players[0].cnt, players[1].cnt); i++){
                if(players[0].points[i] != players[1].points[i])
                            break;
    }
    if(players[0].points[i] > players[1].points[i]){
        COUT << players[0].name << "\n";
        return 0;
    }

    if(players[0].points[i] < players[1].points[i]){
        COUT << players[1].name << "\n";
        return 0;
    }

    if(players[0].points[players[0].cnt - 1] > players[1].points[players[1].cnt - 1]){
        COUT << players[0].name << "\n";
        return 0;
    }else{
        COUT << players[1].name << "\n";
        return 0;
    }
    return 0;
}



