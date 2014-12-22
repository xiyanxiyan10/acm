/**
 * @brief live archive 3971
 * @file 3971.cpp
 * @author mianma
 * @created 2014/12/22 16:23
 * @edited  2014/12/22 16:23
 * @type binart_search
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

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

#define MAXN 1000
#define MAXP 1000000
#define MAXQ 1000000000

int cnt = 0;                            /*compent type tots*/
map<string, int> id;
int n, cases, budget;

int get_id(const string &str){      /*get type id*/
    if(!id.count(str))
        id[str] = cnt++;
    return id[str];
}

struct compent{
    int quality;
    int price;
};

vector<struct compent> table[MAXN + 10];

void init_db(void){
    for(int i = 0; i < cnt; i++)
        table[i].clear();
    cnt = 0;
}
/**
 * @brief  check if we can assemble  a computer 
 * @param[in] min quality of the computer
 * @param[in] budget  of the computer
 */
bool check_compent(int quality, int budget){
    int sum = 0, i, j;
    for(i = 0; i < n; i++){
        int price = MAXP + 10;
        vector<struct compent> &objs = table[i];
        for(j = 0; j < objs.size(); j++){
            struct compent obj = objs[j];
            if(obj.quality < quality)
                    continue;
            else
                price = min(obj.quality, price);
        }
        if(MAXP + 10 == price)
            return false;
        else
            sum += price;    
    }
    return (sum > budget ? false : true);
}

int main(void){
    string type, name;
    int price, quality;
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> cases;
    while(cases--){
        init_db();
        CIN >> n >> budget;
        while(n--){
            CIN >> type >> name >> price >> quality;    
            struct compent obj;
            obj.quality = quality;
            obj.price   = price;
            table[get_id(type)].push_back(obj);
        }
        int lft = 0;
        int rht = MAXQ + 1;
        while(lft < rht){
            int mid = (rht - lft)/2 + lft;
            if(check_compent(mid, budget)){
                rht = mid + 1;
            }else{
                lft = mid;   
            }
        }
        COUT << lft << "\n";
    }
    return 0;
}



