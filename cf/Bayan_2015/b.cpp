/*
 * @brief bayan_2015 b
 * @file b.cpp
 * @author xiyan
 * @CreatedTime 2014/11/04
 * @LastChanged 2014/11/04
 * @note
 *      Comprehensive questions
 *
 */

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
      string ans;
      ans.clear();

      string row_str, col_str;
      CIN >>  row >> col;
      CIN >> row_str >> col_str;

      ans += row_str[0];
      ans += col_str[col - 1];
      ans += row_str[row - 1];
      ans += col_str[0];
#ifdef DEBUG
     cout << ans << endl;
#endif


      if(ans == ">v<^" || ans == "<^>v")
            COUT << "YES" << endl;
      else
            COUT << "NO" << endl;
    return 0;
}



