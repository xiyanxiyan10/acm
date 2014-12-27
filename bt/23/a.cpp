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

#define MAXN 1000

int table[MAXN + 10];
int n, ans, tmp;

void build_table(void)
{
	memset(table, 0, sizeof(table));
	for(int i = 2; i <= 1000; i++){
		for(int j = i; j <= 1000; j+= i)
			if(j > i)
				table[j] = 1;
	}
}


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
     build_table();
     while(CIN >> n){
     	ans = 0;
     	for(int i = 0; i < n; i++){
		CIN >> tmp;
     		if(!table[tmp])
			ans += tmp;
    	}
     	COUT << ans << endl;
    }   
    return 0;
}



