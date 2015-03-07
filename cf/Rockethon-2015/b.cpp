/**
 * @brief Rockethon 2015 b
 * @file b.cpp
 * @author mianma
 * @created 2015/02/27 23:20
 * @edited  2015/02/27 23:20
 * @type 
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

typedef long long int ll;




#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

#define MAXN 50
ll fac[MAXN];
int ans[MAXN];

int n, m;


int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n >> m;
    fac[0] = 1;
    for(int i = 1; i <= n; i++)
	    fac[i] = fac[i - 1] * 2LL;
    int p = 1, q = n;
    for(int i = 1; i <= n; i++){
    	if( m > fac[n - i - 1]){
		m -= fac[n - i - 1];
		ans[q--] = i;
	}else{
		ans[p++] = i;
	}	
    }
    for(int i = 1; i <= n; i++)
	COUT << ans[i] << (i == n ? "\n" : " ");
    return 0;
}



