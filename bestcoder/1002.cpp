#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <stack>
#include <set>

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

long long int x, y, idx, tmp, val, curr, last, cnt, ans;
int cases;

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
      CIN >> cases;
      for(int caseCurr = 1; caseCurr <= cases; caseCurr++){
            CIN >> x >> y >> idx;

            ans = -1;
            cnt = 0;
            last = x;
            last = y < last ? y : last;
            for(curr = last; curr >= 1; curr--){
                    if((x%curr) == 0 && (y%curr == 0)){
                            cnt++;
                        if(cnt == idx){
                            ans = curr;
                            break;
                        }
                    }
            }
            COUT << ans << endl;
      }
    return 0;
}



