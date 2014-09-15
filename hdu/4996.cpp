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


#define MAXN 20

int dp[MAXN][MAXN];
int record[1<<MAXN];
int curr  [1<< MAXN];

#define CLR(vec) memset(vec, 0, sizeof(vec))

void init_dp(void){
    int i, j;
    CLR(dp);
    CLR(record);
    CLR(curr);

    dp[1][1] = 1;
    record[1] = 1;

    for(i = 0; i < 18; i++){
            memcpy(curr, record, sizeof(curr)); 

            for(j = 0; j < (1 << i); j++) if(curr[j]){
                int tot = 0;
                int tmp[20];
            
            
            }
            dp[i + 1][count[]]
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
      int cases;
      CIN >> cases;
      for(int currCase = 1; currCase <= cases; currCase++){
            

      }
    return 0;
}



