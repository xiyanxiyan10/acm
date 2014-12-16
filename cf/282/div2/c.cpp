/**
 * @brief Codeforces Round #282 (Div. 2) c
 * @file c.cpp
 * @author mianma
 * @created 2014/12/16 16:09
 * @edited  2014/12/16 16:09
 * @type math
 * @note
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <cmath>

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

#define MAXN 100010
int ans[MAXN];
string str;
int last;
int tot, cnt;
int n;

int lft, rht; // '{' and '}'

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> str;
    n = str.size();
    for(int i = 0; i <= n - 1; i++)
        if( '#' == str[i]){
            ++tot;
            last = i;
        }
    for(int i = n - 1; i > last; i--){
        if(')' == str[i])
            ++rht;
        else
            --rht;
        if(rht < 0)
            goto fail;
    }
    for(int i = 0; i <= last; i++){
        if('(' == str[i])
            ++lft;
        else if( ')' == str[i])
            --lft;
        else{
            /*get one '#'*/
            if(cnt != tot - 1){
                ans[cnt] = 1;
                --lft;
            }else{
                lft -= rht;
                if(lft >= 1){
                    ans[cnt] = lft;
                    goto success;
                }else
                    goto fail;
            }
            ++cnt;
        }
        if(lft < 0)
            goto fail;
            
    }
success:
    for(int i = 0; i < tot; i++)
        COUT << ans[i] << "\n";
    return 0;
fail:
    COUT << "-1\n";
    return 0;
}



