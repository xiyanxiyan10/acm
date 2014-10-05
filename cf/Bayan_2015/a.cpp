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


#define MAXCOL 11
#define MAXROW 3

#define CLR(vec) memset(vec, 0, sizeof(vec))

int table[MAXROW][MAXCOL];

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
    int n;

#ifdef DEBUG    
while( CIN >> n){
#else
    CIN >> n;
#endif

    int cnt = n;
    CLR(table);
    if(cnt <= 2){
        for(int idx = 0; idx < cnt; idx++)
            table[idx][0] = 1;
    }else{
        cnt--;
        for(int idx = 0; idx < cnt; idx++)
            table[idx%3][idx/3] = 1;
    }

    COUT << "+------------------------+" << endl;


    COUT << "|";
    for(int idx = 0 ; idx < MAXCOL; idx++)
        COUT << (table[0][idx]? 'O': '#') << ".";
    COUT << "|D|)" << endl;

    COUT << "|";
    for(int idx = 0 ; idx < MAXCOL; idx++)
        COUT << (table[1][idx]? 'O': '#') << ".";
    COUT << "|.|" << endl;

    if(n >= 3){
        COUT << "|O.......................|" << endl;
    }else{
        COUT << "|#.......................|" << endl;
    }


    COUT << "|";
    for(int idx = 0 ; idx < MAXCOL; idx++)
        COUT << (table[2][idx]? 'O': '#') << ".";
    COUT << "|.|)" << endl;

    COUT << "+------------------------+" << endl;
#ifdef DEBUG
}
#endif
    return 0;
}



