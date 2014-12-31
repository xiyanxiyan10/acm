/**
 * @brief live archive 3905
 * @file 3905.cpp
 * @author mianma
 * @created 2014/12/24 17:37
 * @edited  2014/12/24 17:37
 * @type 
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

int w, h, cases;
int n;
int x, y, a, b;

#define INF (1e9)

struct event{
#define LFT_EVENT 0
#define RHT_EVENT 1
    bool operator < (const struct event &ev) const {
        return (pos < ev.pos || (pos == ev.pos && type > ev.type));
    }
    int type;
    double pos;
};

void update(int x, int v, int w, double &lft, double &rht){
    if(v == 0){
        if(x <= 0 && x >= w)
            rht = lft - 1;
    }else if(v > 0){
        lft = max(lft, -(double)x/v);
        rht = min(rht, (double)(w - x)/v);
    }else{
        lft = max(lft, (double)(x - w)/v);
        rht = min(rht, (double)x/v);
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",   ios::in);
    COUT.open("./out", ios::out);
#endif
    CIN >> cases;
    vector<struct event> store;
    while(cases--){
        store.clear();
        CIN >> n;
        for(int i = 0; i < n; i++){
            CIN >> x >> y >> a >> b;
            double lft = 0;
            double rht = 1e9;
            update(x, a, w, lft, rht);
            update(y, b, h, lft, rht);
            if(lft >= rht)
                continue;
            struct event ev;
            ev.pos = lft; 
            ev.type = 0;
            store.push_back(ev);
            ev.pos = rht; 
            ev.type = 1;
            store.push_back(ev);
        }
        sort(store.begin(), store.end());
        int ans = -1;
        int cnt = 0;
        for(int i = 0; i < store.size(); i++){
            if(0 == store[i].type){
                    ++cnt;
            }else{
                    --cnt;
            }
            ans = max(cnt, ans);
        }
        COUT << ans << "\n";
    }
    return 0;
}



