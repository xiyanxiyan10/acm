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


#define MAXN 18

int table[MAXN + 10];

int checkKey;               /*max increasing subsequence */    


void listBuild(int start, int end, int *vec){
        int idx, tmp;
        if(start == end){
                //*check if it is vaild*
        }else{
                for(idx = start; idx <= end; idx++){
                    tmp = vec[start]; vec[start] = vec[end]; vec[end] = tmp;          
                    listBuild(start + 1, end, vec);       
                    tmp = vec[start]; vec[start] = vec[end]; vec[end] = tmp;          
                }
        }

}

int listCheck(int start, int end, int *vec){
    vector<int> checkList;
    int idx;
    int cnt     = end - start + 1;          /**tot num in array*/    
    for(int idx = 1; end - idx + 1 >= checkKey; idx++)
        int checkcnt = checkKey;
        checkCnt--;


    while(checkcnt){
    
        checkcnt--;
    }
    return 0;
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
      int cases, N, K, ans;
      CIN >> cases;
      for(int currCase = 1; currCase <= cases; currCase++){
            CIN >> N >> k;
            for(int idx = 1; idx <= N idx+)
                    table[idx] = idx;
            

      }
    return 0;
}



