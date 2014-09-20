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

typedef long long int ll;

ll x, y, idx, tmp, val, last;
int cases;
vector<ll> store;

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
            store.clear();
            while(y){
                tmp = x%y;
                x   = y;
                y   = tmp;
            }
            last = (ll)(sqrt((1.0)*x) + 0.5);
            for(val = 1; val <= last; val++){
                    if(0 == x%val){
                            store.push_back(val);
                            if(val*val != x){
                                store.push_back(x/val);
                        }
                    }
            }
            if(idx > store.size()){
                    COUT << "-1" << endl;
            }else{
                sort(store.begin(), store.end());
                COUT << store[store.size() - idx] << endl;
            }
        }
    return 0;
}



