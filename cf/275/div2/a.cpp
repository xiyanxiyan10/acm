/**
 * @brief Codeforces Round #275 (Div. 2) a
 * @file a.cpp
 * @author 面码
 * @created 2014/12/10 17:27
 * @edited  2014/12/10 17:27
 * @type  brute math
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

ll l, r, mid, lft, rht;
ll division;
int search;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> l >> r;
    if(r - l < 2){
        COUT << "-1\n";
        return 0;
    }
    for( mid = l + 1; mid < r; mid++)
        for(lft = l; lft < mid; lft++)
            for(rht = r; rht > mid; rht--){
                search = 0;
                for(division = 2; division <= 50 && division <= min(lft, mid); division++){
                        if(lft%division == 0 && mid%division == 0){
                                search = 1;
                                break;
                        }
                }
                if( 1 == search){
                    continue;
                }

                search = 0;
                for(division = 2; division <= 50 && division <= min(rht, mid); division++){
                        if(rht%division == 0 && mid%division == 0){
                                search = 1;
                                break;
                        }
                }

                if( 1 == search){
                    continue;
                }

                search = 0;
                for(division = 2; division <= 50 && division <= min(lft, rht); division++){
                        if(rht%division == 0 && lft%division == 0){
                                search = 1;
                                break;
                        }
                }

                if( 1 == search){
                    COUT << lft << " " << mid << " " << rht << "\n";
                    return 0;
                }
            }
    COUT << "-1\n";
    return 0;
}



