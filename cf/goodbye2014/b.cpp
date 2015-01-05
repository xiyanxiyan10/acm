/**
 * @brief good bye 2014 b
 * @file b.cpp
 * @author mianma
 * @created 2014/01/05 16:54
 * @edited  2014/01/05 16:54
 * @type 
 * @note
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <stack>

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

int n, tmp;
int table[MAXN];
int visit[MAXN];
int radix[MAXN];
vector<int> record[MAXN];

set<int> dfs(int curr){
    set<int> ret;
    if(visit[curr])
        return ret;
    stack<int> st;
    st.push(curr);
    while(!st.empty()){
        int pos = st.top();
        ret.insert(pos);
        visit[pos] = 1;
        for(int i = 0; i < record[curr].size(); i++){
            if(visit[record[curr][i]])
                continue;
            st.push(record[curr][i]);
        }
        st.pop();
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
    for(int i = 1; i <= n; i++)
        for(int j = 1; i <= n; j++){
            CIN >> tmp;
            if(tmp)
                record[i].push_back(j);
        }
    for(int i = 1; i <= n; i++){
        set<int> st = dfs(i);
        CLR(radix);
        for(set<int>::iterator iter = st.begin(); iter != st.end(); iter++){
                    ++radix[table[*iter]];
        }
        set<int>::iterator iter = st.begin();
        for(int i = 1; i <= n; i++){
            if(radix[i])
                table[*iter++] = i;
        }
    }
    for(int i = 1; i <=n; i++)
        COUT << table[i] << (i == n ? "\n", " ");
        return 0;
}



