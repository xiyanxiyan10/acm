/**
 * @brief Codeforces Round #294 (Div. 2) b
 * @file b.cpp
 * @author mianma
 * @created 2015/02/28 9:40
 * @edited  2015/02/28 9:40
 * @type sort
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

#define MAXN 100100

int one[MAXN];
int two[MAXN];
int three[MAXN];
int ans_one;
int ans_two;

int n;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    CIN >> n;
    for(int i = 0; i < n; i++)
      CIN >> one[i];
    sort(one, one + n);

    for(int i = 0; i < n -1; i++)
      CIN >> two[i];
    sort(two, two + n - 1);

    for(int i = 0; i < n -2; i++)
      CIN >> three[i];
    sort(three, three + n - 2);

    for(int i = 0; i < n; i++)
        if(one[i] != two[i]){
            ans_one = one[i];
            break;
        }

    for(int i = 0; i < n -1; i++)
        if(two[i] != three[i]){
            ans_two = two[i];
            break;
        }
    COUT << ans_one << "\n";
    COUT << ans_two << "\n";
    return 0;
}



