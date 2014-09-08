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

typedef long long int ll;


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
      ll cases, idx, height, range, len, start, end;
      CIN >> cases;
      while(cases--){
      		CIN >> start >> end;
		len = end - start;
      		idx = 1;
	        height = 1;
		range = 1;
		while(1){
			if(range >= len) 
				break;
			if(idx &0x1){
				range += height;
			}else{
				height++;
				range += height;
			}
			idx++;
		}
		COUT << idx << endl;	
      }
    return 0;
}



