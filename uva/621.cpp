#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#ifdef DEBUG
ifstream in;
ofstream out;
#endif

#ifdef DEBUG
#define CIN  in
#define COUT  out
#else
#define CIN  cin
#define COUT cout
#endif

#define CLR(vec)  memset(vec, 0, sizeof(vec))  

char matchComplete(string str){
    char ret;
    if(str.size() < 4)
            ret = '!';
    if(0 == str.find("190"))
            ret = '?';
    else
            ret = '!';
    return ret;
}

char matchFail(string str){
    char ret;
    if(str.size() < 3)
            ret = '!';
    if('9' == str[0] && '4' == str[str.size() - 1])
            ret = '*';
    else
            ret = '!';
    return ret;   
}

char matchNeg(string str){
    char ret;
    if(str.size() < 3)
            ret = '!';
    if('5' == str[str.size() - 1] && '3' == str[str.size() - 2])
            ret = '-';
    else
            ret = '!';
    return ret;   
}

int  main(void)
{
#ifdef DEBUG
      string buffer;
      CIN.open("in", ios::in);
      COUT.open("out", ios::out);
      while(getline(CIN, buffer))
            COUT << buffer << "\n";
      COUT << "Out Put" << "\n";
      CIN.close();
      CIN.open("in", ios::in);
#endif
      int cases;
      string str;
      CIN >> cases;
      while(cases--){
            char ans;
            CIN >> str;
            do{
                ans = matchFail(str);
                if(ans != '!')
                    break;

                ans = matchComplete(str);
                if(ans != '!')
                    break;

            
                ans = matchNeg(str);
                if(ans != '!')
                    break;

                ans = '+';
            
            }while(0);
            COUT << ans << endl;
      }

    return 0;
}



