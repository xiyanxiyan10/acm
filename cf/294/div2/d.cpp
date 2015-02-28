/**
 * @brief Codeforces Round #294 (Div. 2) c
 * @file c.cpp
 * @author mianma
 * @created 2015/02/28 15:17
 * @edited  2015/02/28 15:17
 * @type greedy
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a))
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))


//#define DEBUG 1


#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif


#define MAXN 100010
#define MAXC 26

typedef long long int ll;

ll totval;

struct num{
    int val;
    int start;
    int last;
    ll totval;
}record[MAXC];

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    CIN >> n;
    for(int i= 0; i < 26; i++){
        CIN >> record[i].val;
        record[i].start = record[i].last = -1;
    }
    CIN >> str;
    for(int i = 0; i < str.size(); i++){
        int ch = str[i] - 'a';
        totval += num[ch].val;

        if(!record[ch].val)
            continue;
        if(record[ch].start < 0){
                record[ch].start == record[ch].last = i;
        }else{

        }

    }
    return 0;
}



