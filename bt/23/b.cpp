#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#ifdef DEBUG
ifstream in;
ofstream out;
#endif

#ifdef DEBUG
#define CIN  in
#define COUT  out
#else
#define CIN  cin
#define COUT cout
#endif

#define MAXN 	105
#define MOD	1000000007
#define CLR(vec) memset(vec, 0, sizeof(vec))

typedef long long int ll;

int n;
int record[MAXN];

/*0: sit after the prev one , 1 sit before prev one*/
int dp[2][MAXN][MAXN];

static inline void check_mod(ll &num){
    if(num > MOD)
        num %= MOD;
}

int  main(void)
{
#ifdef DEBUG
      string buffer;
      CIN.open("in", ios::in);
      COUT.open("out", ios::out);
      while(getline(CIN, buffer))
            COUT << buffer << "\n";
      COUT << "Out Put" << "\n";
      CIN.close();
      CIN.open("in", ios::in);
#endif
    while(CIN >> n){
        CLR(dp);
        CLR(record);
        int pp, p, curr;
        ll tmp;
        for(int i = 1; i <= n; i++){
            pp = p;
            p = curr;
            CIN >> curr;
            if(i >= 3 && pp != curr)
                    record[i] = 1;
        }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++){
                if(record[i]){
                    tmp = 0;
                    for(int k = j + 1; k <= i - 1; k++){
                        tmp+= dp[0][i - 1][k];
                        check_mod(tmp);
                    }
                    dp[1][i][j] = tmp;
                    tmp = 0;
                    for(int k = 1;  k <= j - 1; k++){
                        tmp += dp[0][i - 1][k] + dp[1][i - 1][k];
                        check_mod(tmp);
                    }
                    dp[0][i][j] = tmp;
                }else{
                    tmp = 0;
                    for(int k = 1; k <= i - 1; k++){
                        tmp += dp[0][i - 1][k] + dp[1][i - 1][k];
                        check_mod(tmp);
                    }
                    dp[0][i][j] = dp[1][i][j] = tmp;
                }
           }
           ll ans = 0;       
           for(int i = 1; i <= n; i++){
                ans += dp[0][n][i] + dp[1][n][i];
                check_mod(ans);
           }
           COUT << ans << "\n";
    }   
    return 0;
}



