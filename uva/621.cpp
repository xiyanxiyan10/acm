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
      int cases;
      string str;
      CIN >> cases;
      while(cases--){
            CIN >> str;
            int len = str.size();
            char ans;
            if(len <= 2)
                    ans = '+';
            else if('5' == str[len - 1] && '3' == str[len - 2])
                    ans = '-';
            else if('9' == str[0] && '4' == str[len - 1])
                    ans = '*';
            else
                    ans = '?';
            COUT << ans << endl;
      }

    return 0;
}



