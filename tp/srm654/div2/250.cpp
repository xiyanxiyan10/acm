// BEGIN CUT HERE

// END CUT HERE
#line 5 "SquareScoresDiv2.cpp"
#include <string>
#include <vector>

using namespace std;
class SquareScoresDiv2 {
	public:
	int getscore(string s) {
	    char record = s[0];
        int cnt = 1;
        int ans = 0;
		for(int i = 1; i < s.size(); i++){
            if(record != s[i]){
                for(int j = 1; j <= cnt; j++)
                    ans += cnt - j + 1;
                record = s[i];
                cnt = 1;
            }else{
                ++cnt;
            }
		}
		 for(int j = 1; j <= cnt; j++)
                    ans += cnt - j + 1;
         return ans;
	}
};
