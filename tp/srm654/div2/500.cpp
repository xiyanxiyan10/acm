// BEGIN CUT HEcRE

// END CUT HERE
#line 5 "OneEntrance.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>


#define CLR(vec)  memset(vec, 0, sizeof(vec))
using namespace std;

#define MAXN 150

vector<int> gf[MAXN];
vector<int> nums;
int rec[MAXN];

void dfs(int curr, int father, int key){
    if(rec[curr])
        return;

    if(curr == key){
	rec[key] = 0x1;    
	return;
    }

    for(int i = 0; i < gf[curr].size(); i++){
        int next = gf[curr][i];
        if(next == father || rec[next]){
            continue;
        }
        dfs(next, curr, key);
    }
    return;
}


class OneEntrance {
	public:
	int count(vector <int> a, vector <int> b, int s){
	    for(int i = 0; i < a.size(); i++){
                gf[a[i]].push_back(b[i]);
                gf[b[i]].push_back(a[i]);
            }

	    for(int i = 0; i <= a.size(); i++)
		nums.push_back(i);
		
	    int ans = 0;
	    do{
#ifdef  DEBUG
                cout<< "permuation:\n";
                for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
                    cout<< *iter << " ";
                cout << endl;
#endif
                    CLR(rec);
		    int success = 1;
		    for(int i = 0; i < nums.size(); i++){
			    int key = nums[i];
			    dfs(s, s, key);
			    if(0 == rec[key]){
#ifdef DEBUG
                                cout<< key << " check fail\n";
#endif
				success = 0;
				break;
			    }
		    }
		    if(success) ++ans;
	    }while(next_permutation(nums.begin(), nums.end()));
		
	    return ans;
	}
};

