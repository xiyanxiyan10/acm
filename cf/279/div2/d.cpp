/**
 * @brief Codeforces Round #279 (Div. 2) c
 * @file c.cpp
 * @author 面码
 * @created 2014/11/28 17:14
 * @edited  2014/11/28 17:14
 * @type brute
 * @note TL
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 4000

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

typedef long long int ll;

struct elem{
    int row;
    int col;
    int cost;
};

typedef long long int ll;
typedef map<ll, struct elem> store;
store::iterator lft_ans, rht_ans;
store lft, rht;

int lft_row, rht_row, lft_col, rht_col;

void brute(int row, int col, store &st, int cost){
#ifdef DEBUG
    COUT <<  "row = " << row << "|" << "col = " << col << "|" << "cost = " << cost << "\n";
#endif
    pair<ll, struct elem> tmp;
    tmp.first = row*col;
    tmp.second.row = row;
    tmp.second.col = col;
    tmp.second.cost = cost;
    st.insert(tmp);     

    cost++;
    if(0 == row%2)
        brute(row/2, col, st, cost);
    
    if( 0 == row%3)
        brute(row/3*2, col, st, cost);
    
    if(0 == col%2)
        brute(row, col/2, st, cost);
    
    if(0 == col%3)
        brute(row, col/3*2, st, cost);
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> lft_row >> lft_col;
    CIN >> rht_row >> rht_col;
    brute(lft_row, lft_col, lft, 0);
#ifdef DEBUG
    COUT << "\n\n";
#endif
    brute(rht_row, rht_col, rht, 0);
    store::iterator lft_iter = lft.begin();
    store::iterator rht_iter;

    int min_cost = 0x7fffffff;
    int cost;
    lft_ans = lft.end();
    for(; lft_iter != lft.end(); lft_iter++)
            if( (rht_iter = rht.find(lft_iter->first)) != rht.end()){
                cost = lft_iter->second.cost + rht_iter->second.cost;
                if(cost < min_cost){
                    min_cost = cost;
                    lft_ans = lft_iter;
                    rht_ans = rht_iter;
                }
            }

    if(lft_ans == lft.end()){
        COUT << "-1\n";
    }else{
        COUT << min_cost << "\n";
        COUT << lft_ans->second.row << " " << lft_ans->second.col << "\n";
        COUT << rht_ans->second.row << " " << rht_ans->second.col << "\n";
    }
    return 0;
}



