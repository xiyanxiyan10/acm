/**
 * @brief Codeforces Round #284 (Div. 2) b
 * @file b.cpp
 * @author mianma
 * @created 2014/12/26 11:51
 * @edited  2014/12/26 11:51
 * @type brute
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))
#define PI         acos(-1.0)

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

struct handle{
    string org;
    string curr;
};

vector<struct handle> table;   /*record query accept*/
set<string> used;              /*name used*/
string org, curr;

int table_update(vector<struct handle> &table, string org, string curr){
    vector<struct handle>::iterator iter;
    for(iter = table.begin(); iter != table.end(); iter++){
        if(iter->curr == org){      /*find and reset status*/
            iter->curr = curr;
            return 0;
        }
    }   
    struct handle h;                /*and a new one if not find*/
    h.org = org;
    h.curr = curr;
    table.push_back(h);
    return 1;   
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    for(int i = 0; i < n; i++){
        CIN >> org >> curr;
        if(used.end() != used.find(curr))
            continue;
        int ret = table_update(table, org, curr);
#ifdef DEBUG
        for(int i = 0; i < table.size(); i++){
            COUT << table[i].org << " " << table[i].curr << "\n"; 
        }
        COUT << "\n";
#endif
        used.insert(org);
        used.insert(curr);
    }
    COUT << table.size() << "\n";
    for(int i = 0; i < table.size(); i++){
            COUT << table[i].org << " " << table[i].curr << "\n"; 
    }
    return 0;
}



