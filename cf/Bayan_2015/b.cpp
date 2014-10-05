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


#define MAXCOL 22
#define MAXROW 22
#define MAXPOS (MAXCOL * MAXROW) 

#define CLR(vec) memset(vec, 0, sizeof(vec))

vector<int> table[MAXPOS];

int visit[MAXPOS];


void dfs(int pos, int startPos){
    if()


}


int checkPos(int pos){
    CLR(visit);
    
}


/**多源最短路径思路 + 闭包传递？*/

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
      int row, col;
      char tmp;
      CIN >>  row >> col;

      /* build graph*/
      for(int i = 0 ; i < row; i++){
            CIN >> tmp;
            if( '>' == tmp){
                for(int j = 0; j + 1 < col; j++){
                        table[row*i + j].push_back(row*i + j + 1);
                }
            }else{
                for(int j = 1; j < col; j++){
                        table[row*i + j].push_back(row*i + j - 1);
                }
            }
      }


      for(int j = 0 ; j < col; j++){
            CIN >> tmp;
            if( 'v' == tmp){
                for(int i = 0; i + 1 < row; i++){
                        table[row*i + j].push_back(row*(i + 1) + j);
                }
            }else{
                for(int i = 1; i < row; i++){
                        table[row*i + j].push_back(row*(i - 1) + j);
                }
            }
      }
    
      int success = 0;
      int totPos = (row - 1)*(col - 1);
      for(int pos = 0; pos < totPos; pos++){
            if(checkPos(pos) < 0){
                        success = -1;
                        break;
            }
      }
      COUT << (success ? "YES" : "NO") << endl;
    return 0;
}



