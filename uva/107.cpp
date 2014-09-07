#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cfloat>

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

#define DEQ(x, y) ( (x + FLT_EPSILON) > y && (x - FLT_EPSILON) < y)

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

      double height, work;
      while(CIN >> height >> unworks && height && unwork){
      		int n = 0;
		while( !DEQ(log(n)/log(n + 1), log(work)/log(height)))
			n++;
			

      }
    return 0;
}



