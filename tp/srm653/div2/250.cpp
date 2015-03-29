// BEGIN CUT HERE

// END CUT HERE
#line 5 "ValueOfString.cpp"
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

#define MAXN 26

#define CLR(vec) memset(vec, 0, sizeof(vec))

using namespace std;

class ValueOfString {
	public:
	int findValue(string s) {
           CLR(table);
           for(int i = 0; i < s.size(); i++)
                ++table[s[i] - 'a'];

           for(int i = 0; i < MAXN; i++){
                table[i] = i == 0 ? table[i] : table[i] + table[i - 1];
                //cout << table[i] << endl;
           }
           int sum = 0;
           for(int i = 0; i < s.size(); i++){
                sum += table[s[i] - 'a']*(s[i] - 'a' + 1);
                cout << sum << endl;
           }
           return sum;
	}
	private:
        int table[MAXN];
};
/*
int main(int argc, char **argv)
{
    string str;
    class ValueOfString v;
    cin >> str;
    cout << v.findValue(str) << endl;
   return 0;
}
*/
