/**
 * @brief Codeforces Round #286 (Div. 2) a
 * @file a.cpp
 * @author mianma
 * @created 2014/01/19 09:30
 * @edited  2014/01/19 09:30
 * @type brute
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>

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

string str;

/*idx to find the char*/
static inline int idx_to_ch(const string &str, const int &curr, const int &pos, const int &ch){
    return (curr == pos ? ch : (curr > pos ? str[curr - 1] : str[curr]) );
}

/*check pa*/
static inline int check_pa(const string &str, const int &pos, const int &ch){
    for(int i = 0, j = str.size(); i < j; i++, j--)
        if(idx_to_ch(str, i, pos, ch) != idx_to_ch(str, j, pos, ch))
                    return -1;
    return 0;
}

/*output the string insert char ch into pos */
static inline string out_pa(const string &str, const int &pos, const int &ch){
    string ret;
    for(int i = 0; i <= str.size(); i++)
        ret += idx_to_ch(str, i, pos, ch);
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> str;
    for(int pos = 0; pos <= str.size(); pos++)
        for(int ch = 'a'; ch <= 'z'; ch++)
            if(!check_pa(str, pos, ch)){
                    COUT << out_pa(str, pos, ch) << "\n";
                    return 0;
            }
    COUT << "NA\n";
    return 0;
}



