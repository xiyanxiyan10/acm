/**
 * @brief live archive 3695
 * @file 3695.cpp
 * @author mianma
 * @created 2014/01/09 10:44
 * @edited  2014/01/09 10:44
 * @type comprehensive
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

#define MAXN     (100 + 10)

struct pos{
	int x, y;
	bool operator < (const struct pos &p) const{
		return x < p.x;
	}
}table[MAXN];

int lft[MAXN], on[MAXN], on2[MAXN];     /*counter*/
int y[MAXN];                            /*used for brute*/
int n;                                  /*tot pos*/

int solve(void){
	int ans = -1;
	sort(y, y + n);
	int m = unique(y, y + n) - y;
	if(m <= 2)
		return n;
	sort(table, table + n);
	for(int i = 0; i < m; i++)
		for(int j = i + 1; j < m; j++){
			int cnt = 0;                    /*tot perpendiculars*/
			int miny = y[i];
			int maxy = y[j];
			for(int k = 0; k < n; k++){
				if( 0 == k || table[k - 1].x != table[k].x){
					++cnt;
					on[cnt] = on2[cnt] = 0;
					lft[cnt] = 0 == k ? 0 : (lft[cnt - 1] + on2[cnt - 1] - on[cnt - 1]);
				}
				if(table[k].y < maxy && table[k].y > miny) ++on[cnt];
				if(table[k].y <= maxy && table[k].y >= miny) ++on2[cnt];
			}
			int m = 0;
			for(int k = 1; k <=cnt; k++){
				ans = max(on2[k] + lft[k] + m, ans);
				m = max(on[k] - lft[k], m);
			}
		}
	return ans;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",   ios::in);
    COUT.open("./out", ios::out);
#endif
    int kcase = 1;
    while(CIN >> n && n){
    	for(int i = 0; i < n; i++){
		CIN >> table[i].x >> table[i].y;
		y[i] = table[i].y;
	}
	COUT << "Case " << kcase++ << ": " << solve() << "\n";
    }
    return 0;
}



