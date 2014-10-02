/*
 * @brief 题解
 * @file c.cpp
 * @author xiyanxiyan10
 * @CreatedTime 2014/10/02
 * @LastChanged 2014/10/02
 * @note 
 *      规律, 规律题目
 *      当 n < 4时无解
 *      当 n > 4时，如果n为偶数，则通过前4个数构造24，其余的数两两构造1
 *      当 n > 4时  如果n为奇数，则通过前3个数构造24，其余的数两两构造1
 */

#include <iostream>
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


#define oddStr  "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
#define evenStr "3 * 5 = 15\n2 * 4 = 8\n15 + 8 = 23\n23 + 1 = 24\n";


#ifdef DEBUG
void debugInit(void)
{
      string buffer;
      CIN.open("in", ios::in);
      COUT.open("out", ios::out);
      while(getline(CIN, buffer))
            COUT << buffer << "\n";
      COUT << "Out Put" << "\n";
      CIN.close();
      CIN.open("in", ios::in);
}
#endif


int main()
{
#ifdef DEBUG
    debugInit();
#endif
    int n;
    CIN >> n;
    if(n < 4){
        COUT << "NO" << "\n";
    }else{
        COUT << "YES" << "\n";
        if(n&0x1){
                COUT << evenStr;
                for(int i = 6; i < n; i+= 2){
                        COUT << (i + 1)  << " - " << i << " = " << "1\n";
                        COUT << "24 * 1 = 24\n";
                }
        }else{
                COUT << oddStr;
                for(int i = 5; i < n; i+= 2){
                        COUT << (i + 1)  << " - " << i << " = " << "1\n";
                        COUT << "24 * 1 = 24\n";
                }
        }
    }
    return 0;
}
