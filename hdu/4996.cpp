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


typedef long long int ll;


ll dp[MAXN][MAXN];
ll record[1<<MAXN];
ll curr  [1<<MAXN];

int cset(int val){
    int cnt = 0;
    for(int idx = 0; idx < MAXN; idx++) if(val &(1 << idx))
            cnt++;
    return cnt;   
}

void init_dp(void){
    int len, val;
    CLR(dp);
    CLR(record);
    CLR(curr);
    dp[1][1] = 1;
    curr[1] = 1;
    for(len = 1; len < 18; len++){
            for(int status = 0; status < ( 1 << len); status++)
                record[status] = curr[status];
            for(int status = 0; status < ( 1 << (len + 1)); status++)
                curr[status] = 0;
            for(int oldstatus = 0; oldstatus < (1 << len); oldstatus++) if(record[oldstatus]){
                    for(val = 0; val <= len; val++){
                        int tot = 0;
                        int tmp[20];
                        for(int idx = 0; idx < len; idx++) if(oldstatus & (1 << idx))
                                    tmp[tot++] = idx;
                        for(int idx = 0; idx < tot; idx++) if(tmp[idx] >= val)
                                    tmp[idx]++;
                        tmp[tot++] = val;
                        for(int idx = 0; idx < tot; idx++) if(tmp[idx] > val){
                                    tmp[idx] = val; 
                                    break;
                        }
                        int newstatus = 0;
                        for(int idx = 0; idx < tot; idx++)
                                    newstatus |= ( 1 << tmp[idx]);
                        curr[newstatus] += record[oldstatus];
                    }
            }
        for(int status = 0; status < ( 1 << (1 + len)); status++)    
            dp[1 + len][cset(status)] += curr[status];
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
            CIN >> n >> k;
            COUT  << dp[n][k] << endl;

      }
    return 0;
}



