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

#define MAXN 2500

struct range{
    int beginIdx;
    int endIdx;
};


int ptable[MAXN + 10];
vector<struct range> qrange;


#define CLR(vec) memset(vec, 0, sizeof(vec))


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
      CLR(ptable);
      qrange.clear();
    
     int p, q, l, r;
     int beginIdx, endIdx;
     CIN >> p >> q >> l >> r;
     while(p--){
        CIN >> beginIdx >> endIdx;
        for(int idx = beginIdx; idx <= endIdx; idx++)
                ptable[idx] = 1;

     }
     while(q--){
        struct range rg;
        CIN >> rg.beginIdx >> rg.endIdx;
        qrange.push_back(rg);
     }
     int ans = 0;
     for(int offset = l ; offset <= r; offset++){
            int flag = 1;
            for(vector<struct range>::iterator rgp = qrange.begin(); rgp != qrange.end() && flag ;rgp++){
                        beginIdx = rgp->beginIdx  + offset;
                        endIdx  =  rgp->endIdx    + offset;
                        for(int idx = beginIdx; idx <= endIdx; idx++){
                                if(ptable[idx]){
                                           ans++;
                                           flag = 0;
                                           break;
                                }
                        }
            }
     }
     COUT << ans << endl;
    return 0;
}



