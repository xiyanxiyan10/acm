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

#define CLR(vec) memset(vec, 0, sizeof(vec))
#define MAXN 20

int dp[MAXN][MAXN];
int record[1<<MAXN];
int curr  [1<<MAXN];

int cset(int val){
    int cnt = 0;
    while(val){
        val &= (val - 1);
        cnt++;
    }
    return cnt;   
}


void init_dp(void){
    int i, j, k;

    dp[1][1] = 1;
    curr[1] = 1;
    for(i = 1; i < 18; i++){
            for(int idx = 0; idx < ( 1 << i); idx++){
                record[idx] = curr[idx];
                curr[idx]   = 0;
            }
            for(j = 0; j < (1 << i); j++) if(record[j]){
                    for(k = 0; k <= i; k++){
                        int tot = 0;
                        int tmp[20];
                        for(int idx = 0; idx < i; idx++) if(j & (1 << idx))
                                    tmp[tot++] = idx;
                        for(int idx = 0; idx < tot; idx++) if(tmp[idx] >= k)
                                    tmp[idx]++;
                        tmp[tot++] = k;
                        for(int idx = 0; idx < tot; idx++) if(tmp[idx] > k){
                                    tmp[idx] = k; 
                                    break;
                        }
                        int st = 0;
                        for(int idx = 0; idx < tot; idx++)
                                    st |= ( 1 << tmp[idx]);
                        curr[st] += record[j];
#ifdef DEBUG
            //            cout << st << " += "  << record[j] << endl;
#endif
                    }
            }
        for(k = 0; k < (1<< (1 + i)); k++)    
            dp[i + 1][cset(k)] += curr[k];
    } 
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
      init_dp();
      int cases, n, k;
      CIN >> cases;
      for(int currCase = 1; currCase <= cases; currCase++){
            CIN >>  n >> k;
            COUT  << dp[n][k] << endl;

      }
    return 0;
}



