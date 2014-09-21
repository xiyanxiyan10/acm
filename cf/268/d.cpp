#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <cstdio>

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
//#define MAXN 1000000200

int valTable[MAXN];
int idxTable[MAXN];

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
      int n, a, b, val, oval;
      CIN >> n >> a >> b;
      for(int i = 1; i <= n; i++){
            scanf("%d", &(val));
            valTable[i] = val;
            idxTable[val]= i;
      }
      int failFlag = 0;
      for(int i = 1; i <= n; i++){
            if(valTable[i] < 0)
                continue;
            if(failFlag)
                break;

            do{
                oval = a - valTable[i];
                if(oval >= 1 && idxTable[oval]){
                    valTable[idxTable[oval]] = -1;
                    valTable[i] = -1;
                    break;
                }

                oval = b - valTable[i];
                if(oval >= 1 && idxTable[oval]){
                    valTable[idxTable[oval]] = -2;
                    valTable[i] = -2;
                    break;
                }
                if(valTable[i] > 0)
                        failFlag = 1;
            }while(0);
      }
      if(failFlag)
            printf("NO\n");
      else{
            printf("YES\n");
            for(int idx = 1; idx < n; idx++){
                printf("%s ", (valTable[idx] == -1 ? "0" : "1"));
            }
            printf("%s\n", (valTable[n] == -1 ? "0" : "1"));
      }
    return 0;
}



