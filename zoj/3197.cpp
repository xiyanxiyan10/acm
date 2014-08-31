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
            for(int currLine = 1; currLine <= line; currLine++){
                CIN >> start >> end;
                rangeTable[start] = rangeTable[start] < end ? end : rangeTable[start];
            }
            int start = 1;      /*range wait to be used */
            int blank = 1;      /*blank range start pos*/
            int ans   = 0;
            end = line;
            while(blank <= end){
                int choose;
                int mark = -1;
                for(; start <= blank; start++){
                        if(rangeTable[start] >= blank && rangeTable[start]>= mark){
                                    choose = start;
                                    mark   = rangeTable[start];
                        }
                }
                start = choose + 1;
                blank = mark + 1;
            }
            COUT << ans << "\n";
      }
    return 0;
}



