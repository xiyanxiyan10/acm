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

#define MAXN 5000

int rangeTable[MAXN + 10];

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
      int cases, line, start, end;
      CIN >> cases;
      for(int currCase = 1; currCase <= cases; currCase++){
            CLR(rangeTable);
            CIN >> line;
            
            int stop  = -1;
            for(int currLine = 1; currLine <= line; currLine++){
                CIN >> start >> end;
                rangeTable[start] = rangeTable[start] < end ? end : rangeTable[start];
                stop = stop < end ? end : stop;
            }

            int blank = 1;       
            int ans   = 0;
            while(blank <= stop){

                int mark = blank;
                for(int idx = 1; idx <= blank; idx++){
                        if(rangeTable[idx] >= mark){
                                    mark   = rangeTable[idx];
                        }
                }
                blank = mark + 1;
                ans++;
            }

            COUT << ans << "\n";
      }
    return 0;
}



