/**
 * @brief Codeforces Round #285 (Div. 2) c
 * @file c.cpp
 * @author mianma
 * @created 2015/01/12 11:51
 * @edited  2015/01/12 11:51
 * @type 
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <stack>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))
#define PI         acos(-1.0)

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

#define MAXN 100000

struct pos{
	int d;
	int s;
}table[MAXN];

int n;
stack<int> st;
vector< pair<int, int> > ans;

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    for(int i = 0 ; i < n; i++){
 	CIN >> table[i].d >> table[i].s;
	if(1 == table[i].d)
		st.push(i);
    }
    while(!st.empty()){
    	int curr = st.top();
	st.pop();
	if(1 == table[curr].d){
		int next = table[curr].s;
		table[next].d -= 1;
		table[next].s ^= curr;
		ans.push_back(make_pair(curr, next));
		if(1 == table[next].d)
			st.push(next);
	}
    }
    COUT << ans.size() << "\n";
    for(int i = 0 ; i < ans.size(); i++)
	    COUT << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}



