#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
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

set<int> lftTable;
set<int> rhtTable;


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
      int cnt, tmp;
      while(CIN >> cnt){
          lftTable.clear();
          rhtTable.clear();
            for(int idx = 0; idx < cnt; idx++){
                CIN >> tmp;
                lftTable.insert(tmp);
            }
            for(int idx = 0; idx < cnt; idx++){
                CIN >> tmp;
                rhtTable.insert(tmp);
            }
            int flag = 0;
            do{
                if(lftTable.size() != rhtTable.size())
                        break;
                set<int>::iterator lft_iter = lftTable.begin();
                set<int>::iterator rht_iter = rhtTable.begin();
                while(lft_iter != lftTable.end() && *lft_iter == *rht_iter){
                        lft_iter++;
                        rht_iter++;
                }
                if(lft_iter == lftTable.end())
                    flag = 1;    
            }while(0);
            COUT << ( flag ? "YES" : "NO") << endl;
      }
    return 0;
}



