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
      ll cases, ans, height, len, start, end;
      CIN >> cases;
      while(cases--){
      		CIN >> start >> end;
		len = end - start;
      		ans = 0;
	        height = 1;
		bool flag = 0;
		while(len > 0){
		        len -= height;

			if(flag)
				height++;
                        flag = !flag;
			ans++;
		}
		COUT << ans << endl;	
      }
    return 0;
}



