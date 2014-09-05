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

#define CLR(vec)  memset(vec, 0, sizeof(vec))  
#define MAXN 50

int table[MAXN + 10];

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
      int tots;
      int idx;
      int sum;
      int avg;
      int ans;
      int curr_cases = 1;
      while(CIN >> tots && tots){
                CLR(table);
                sum = 0;

                if(curr_cases != 1)
                    COUT << "\n";

                for(idx = 0; idx < tots; idx++){
                        CIN >> table[idx];
                        sum += table[idx];  
                }
                avg = sum/tots;
                
                ans = 0;
                for(idx = 0; idx < tots; idx++){
                        ans += table[idx] > avg ? table[idx] - avg : 0;
                }

                COUT << "Set #" << curr_cases++ << "\n";
                COUT << "The minimum number of moves is " << ans << "." << "\n";
      }
    return 0;
}



