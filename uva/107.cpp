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
      int heightTot, unwork;
      while(CIN >> height >> work && height && work){
      		double n = 1;
		while( abs(log(n)/log(n + 1.0)  - log(work)/log(height)) > 1e-9)
			n++;
#ifdef DEBUG
		cout << "n = " << n << endl;
#endif
		int dep = (int)floor(log(height)/log(n + 1) + 0.5);

		if(1 == n)
			unwork = dep;
		else
			unwork = (int)floor( ( 1 - pow(n, dep))/(1 - n) + 0.5);

		heightTot = (int)floor( ( 1 - pow(n/(n+1), dep + 1))*(n + 1)*height + 0.5);
		COUT << unwork << " " << heightTot << endl;
      }
    return 0;
}



