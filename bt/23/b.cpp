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

#define MAXN 	100
#define MOD	1000000007
typedef long long int ll;

int table[MAXN + 10];
int record[MAXN + 10];

int n;
ll ans;

void inline  check_num(ll &num){
	if(num > MOD)
		num = num%MOD;
}

void brute(int idx, int lft, ll cnt){
	if(idx > n){
		ans += cnt;
		check_num(ans);
		return;
	}
	if(idx == 1){
		cnt = lft;
		brute(idx + 1, lft - 1, cnt);
		return;
	}
	if(0 == record[idx]){
		cnt *= lft;
		check_num(cnt);
		brute(idx + 1, lft - 1, cnt);
	}else{
		brute(idx + 1, lft, cnt);
		cnt *= lft;
		check_num(cnt);
		brute(idx + 1, lft - 1, cnt);
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
     while(CIN >> n){
     	ans = 0;
     	for(int i = 1; i <= n; i++)
    		CIN >> table[i];
	
	memset(record, 0, sizeof(record));
     	for(int i = 2; i < n; i++)
    		if(table[i - 1] != table[i + 1])
			record[i] = 1;
	brute(1, n, 0);
     	COUT << ans << endl;
    }   
    return 0;
}



