/**
 * @brief Codeforces Round #294 (Div. 2) a
 * @file a.cpp
 * @author mianma
 * @created 2015/02/28 21:34
 * @edited  2015/02/28 21:34
 * @type
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



//#define DEBUG 1
#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

#define MAXN 300
string ch;

int table[300];



int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in.txt",  ios::in);
    COUT.open("./out.txt",  ios::out);
#endif
    table['q'] = 9;
    table['r'] = 5;
    table['b'] = 3;
    table['n'] = 3;
    table['p'] = 1;

    table['Q'] = 9;
    table['R'] = 5;
    table['B'] = 3;
    table['N'] = 3;
    table['P'] = 1;

    int white = 0;
    int black = 0;

    char ch;
    int *goal;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            CIN >> ch;
            if('.' == ch)
                continue;
            if( 'a' <= ch && ch <= 'z')
                goal = &black;
            else
                goal = &white;

            *goal += table[ch];
        }
        if(white == black)
            COUT << "Draw\n";
        else if(white > black)
            COUT << "White\n";
        else
            COUT << "Black\n";

#ifdef DEBUG
        COUT << white << " " << black << endl;
#endif // DEBUG
    return 0;
}



