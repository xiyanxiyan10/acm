// BEGIN CUT HERE

// END CUT HERE
#line 5 "RockPaperScissorsMagicEasy.cpp"
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAXN (2010)
#define MAXS (2010)
#define MOD  (1000000007LL)

using namespace std;

typedef long long int ll;

ll dp[MAXN][MAXS];

class RockPaperScissorsMagicEasy {
	public:
	int count(vector <int> card, int score) {
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 2;
        dp[1][1] = 1;
        int n = card.size();
        for(int i = 2; i <= n; i++)
        for(int j = 0; j <= score; j++)
        {
            if(j){
                dp[i][j] += dp[i - 1][j - 1];
                checkMod(dp[i][j]);
            }
            dp[i][j] += dp[i - 1][j]*2;
            checkMod(dp[i][j]);
        }
        return (int)dp[n][score];
	}
	void checkMod(ll &n){
        if(n >= MOD)
            n %= MOD;
	}
};


