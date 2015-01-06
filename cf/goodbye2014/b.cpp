/**
 * @brief good bye 2014 b
 * @file b.cpp
 * @author mianma
 * @created 2014/01/06  10:20
 * @edited  2014/01/06  10:20
 * @type dfs greedy 
 * @note
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
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

#define MAXN 320

int n;
int table[MAXN];
int visit[MAXN];
vector<int> store;
vector<int> record[MAXN];

set<int> dfs(int root){
    int pos = root;
    set<int> ret;
    if(visit[pos])
        return ret;
    stack<int> st;
    st.push(pos);
    while(!st.empty()){
        int pos = st.top();
        st.pop();
        ret.insert(pos);
        visit[pos] = 1;
        for(int i = 0; i < record[pos].size(); i++){
            if(visit[record[pos][i]])
                continue;
            st.push(record[pos][i]);
        }
    }
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> n;
    for(int i = 1; i <= n; i++)
        CIN >> table[i];
	
    char ch;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            CIN >> ch;
            if('1' == ch)
                record[i].push_back(j);
        }
    for(int i = 1; i <= n; i++){
	store.clear();
        set<int> st = dfs(i);
	if(st.empty())
		continue;
        for(set<int>::iterator iter = st.begin(); iter != st.end(); iter++)
                    store.push_back(table[*iter]);
	sort(store.begin(), store.end());
        set<int>::iterator iter = st.begin();
        for(int i = 0; i < store.size(); i++, iter++)
                table[*iter] = store[i];
    }
    for(int i = 1; i <=n; i++)
        COUT << table[i] << (i == n ? "\n": " ");
        return 0;
}



