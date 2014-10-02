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

#define MAXN 100

#define SUCCESS "I become the guy."
#define FAIL    "Oh, my keyboard!"


int table[MAXN + 10];

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
      int level, xcnt, ycnt, xpass, ypass;
      CLR(table);
      CIN >> level;
      CIN >> xcnt;
      while(xcnt--){
            CIN >> xpass;
            table[xpass] = 1;
      }
      CIN >> ycnt;
      while(ycnt--){
            CIN >> ypass;
            table[ypass] = 1;
      }
      int flag = 1;  
      for(int idx = 1; idx <= level; idx++){
                if(0 == table[idx]){
                            flag = 0;
                            break;
                
                }
      }
      COUT << (flag ? SUCCESS : FAIL) << endl;
    return 0;
}



