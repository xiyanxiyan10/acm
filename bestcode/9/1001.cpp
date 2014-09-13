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
      int cases, a, b, c, ans;
      CIN >> cases;
      for(int currCase = 1; currCase <= cases; currCase++){
            CIN >> a >> b >> c;
            ans = 0;
            for(int x = 1; a*x < c; x++){
                if(0 == (c - a*x)%b)
                        ans++;
            }
            COUT << ans << "\n";
      }
    return 0;
}



