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


#define DEQ(x, y) ( (x + DBL_EPSILON) > y && (x - DBL_EPSILON) < y)

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

      int height, work;
      int heightTot, unwork;
      while(CIN >> height >> work && height && work){
      		int n = 1;
		while( !DEQ(log((double)n)/log((double)n + 1.0), log((double)work)/log((double)height)))
			n++;
#ifdef DEBUG
		cout << "n = " << n << endl;
#endif

		int heightTot = 0;
		int workTot   = 0;
	        int workCurr  = 1;	
#ifdef DEBUG
		int dep = 1;
#endif
		while(workCurr <= work){

#ifdef DEBUG
			cout << "workCurr = " << workCurr << "work = " << work << endl;
#endif
			heightTot += workCurr*height;
			workTot   += workCurr;		
			workCurr  *= n;
			height    /= (n + 1); 
#ifdef DEBUG
			dep++;
#endif
		}
#ifdef DEBUG
		cout << "dep = " << dep << endl;
#endif
		unwork = workTot - work;
		COUT << unwork << " " << heightTot << endl;

      }
    return 0;
}



