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
      int row, col;
      char tmp;
      CIN >>  row >> col;

      string str;
      str.clear();
      for(int i = 1 ; i <= row; i++){
            CIN >> tmp;
            if(i == 1){
                str += tmp;
            }

            if(i == row){
                str += tmp;
            }
      }
      for(int i = 1 ; i <= col; i++){
            CIN >> tmp;
            if(i == 1){
                str += tmp;
            }

            if(i == row){
                str += tmp;
            }
      }

      if(str == "<>v^" || str == "><^v")
            COUT << "YES" << endl;

            COUT << "NO" << endl;
    return 0;
}



