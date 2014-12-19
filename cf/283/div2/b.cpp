/**
 * @brief Codeforces Round #283 (Div. 2) b
 * @file b.cpp
 * @author mianma
 * @created 2014/12/19 10:50
 * @edited  2014/12/19 10:50
 * @type brute
 * @note
 */
#include <fstream>
#include <iostream>
#include <cstring>

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

#define MAXN 1010

int n;
int table[MAXN];
int record1[MAXN];
int record2[MAXN];

int tmp;
string str;
int *old_record;
int *curr_record;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    CIN >> str;
    for(int i = 0; i < n; i++)
        table[i] = str[i] - '0';

    tmp = table[0];
    old_record = record1;
    curr_record = record2;

    for(int i = 0; i < n; i++){
        if(table[i] >= tmp)
            old_record[i] =  table[i] - tmp;
        else
            old_record[i] =  10 + table[i] - tmp;
    }
    for(int i = 1; i < n; i++){
        tmp = table[n - 1];
        memmove(table + 1, table, sizeof(int) * (n - 1));
        table[0] = tmp;

        int flag  = 0;  /*curr < old ? 1 : 0*/

        for(int j = 0; j < n; j++){
            if(table[j] >= tmp)
                curr_record[j] =  table[j] - tmp;
            else
                curr_record[j] =  10 + table[j] - tmp;
            if( 0 == flag ){
                if(curr_record[j] < old_record[j])
                    flag = 1;

                if(curr_record[j] > old_record[j])
                    break;
            }
        }
        if( 1 == flag){
            int *swp_record = old_record;
            old_record = curr_record;
            curr_record = swp_record;
        }
    }
    for(int i = 0; i < n; i++)
            COUT << old_record[i];
    COUT << "\n";
    return 0;
}



