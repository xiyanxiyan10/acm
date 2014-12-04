/**
 * @brief Codeforces Round #281 (Div. 2) a
 * @file a.cpp
 * @author 面码
 * @created 2014/12/04 17:49
 * @edited  2014/12/04 17:49
 * @type 
 *
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

typedef stack<int> bbq;

#define MAXN 110

struct team{
    string name;        /*tream name*/
    int players[MAXN];    /*card record*/
}team_table[2];

struct event{
    int idx;           /*0 is home, 1 is away*/
    int color;          /*0 is yellow, 1 is read*/
    int num;            /*which player get this*/    
    int timestamp;      /*event occured time*/
};

struct event event_table[MAXN];

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

int n;

int cmp(const void *lft, const void * rht){
    return ( ((struct event *)lft)->timestamp - ((struct event*)rht)->timestamp);
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> team_table[0].name;
    CIN >> team_table[1].name;
    CIN >> n;
    char tmp;
    for(int i = 0; i < n; i++){
        CIN >> event_table[i].timestamp;
        CIN >> tmp;
        event_table[i].idx = tmp == 'h' ? 0 : 1;
        CIN >> event_table[i].num;
        CIN >> tmp;
        event_table[i].color = tmp == 'y' ? 1 : 2;
    }
    qsort(event_table, n, sizeof(struct event), cmp);

    struct  team *team_curr;
    int num;

    for(int i = 0; i < n; i++){
        num = event_table[i].num;
        team_curr = &team_table[event_table[i].idx];
        team_curr->players[num] += event_table[i].color;
        if(team_curr->players[num] > 1){
            COUT << team_curr->name << " " << num << " " << event_table[i].timestamp << endl;
        }
    }
    return 0;
}



