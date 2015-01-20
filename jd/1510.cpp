/**
 * @brief jiudu oj 1510
 * @file 1510.c
 * @author 面码
 * @created 2015/01/20 14:23
 * @edited  2015/01/20 14:23
 * @type string
 * @RR
 * 
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN  in
#define COUT out  
#else
#define CIN  cin
#define COUT cout
#endif

const string p = "%20";

int main()
{
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in", ios::in);
    COUT.open("./out", ios::out);
#endif
    string str;
    string ans;
    while(getline(CIN, str)){
        ans.clear();
        for(int i = 0; i < str.size(); i++){
            if(' ' == str[i]){
                ans += p;
            }else{
                ans += str[i];
            }
        }
        COUT << ans << "\n";
    }
    return 0;
}


