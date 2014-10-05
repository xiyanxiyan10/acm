#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <cctype>

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

const int MAXLen = 10;


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
        string stri;
        string stra;
        string strb;
        long long int vali;
        long long int vala;
        long long int valb;
        int flagi;
        while(CIN >> stri){
            CIN >> stra >> strb;

            int success = 1;
            do{
                if( '-' == stra[0]){
                        stra.erase(0, 1);
                        while(stra.size() > 1 && '0' == stra[0])
                                        stra.erase(0, 1);
                        vala = atoll(stra.c_str());
                        vala = 0 - vala;
                }else{
                        while(stra.size() > 1 && '0' == stra[0])
                                        stra.erase(0, 1);
                        vala = atoll(stra.c_str());
                }
                if( '-' == strb[0]){
                        strb.erase(0, 1);
                        while(strb.size() > 1 && '0' == strb[0])
                                        strb.erase(0, 1);
                        valb = atoll(strb.c_str());
                        valb = 0 - valb;
                }else{
                        while(strb.size() > 1 && '0' == strb[0])
                                        strb.erase(0, 1);
                        valb = atoll(strb.c_str());
                }
#ifdef DEBUG
                COUT << "vala = " << vala << endl;
                COUT << "valb = " << valb << endl;
#endif      

#ifdef DEBUG
COUT << "stri ->"  << stri << endl;
#endif

                if( '-' == stri[0]){
                        stri.erase(0, 1);
                        while(stri.size() > 1 && '0' == stri[0])
                                        stri.erase(0, 1);
                        flagi = -1;
                }else{
                        while(stri.size() > 1 && '0' == stri[0])
                                        stri.erase(0, 1);
                        flagi = 0;
                }
#ifdef DEBUG
COUT << "stri ->"  << stri << endl;
#endif
                if(stri.size() > MAXLen){
                        success = 0;
                        break; 
                }


                if(flagi < 0 && stri.size() == 1 && '0' == stri[0]){
                        success = 0;
                        break;
                }

                for(string::iterator iter = stri.begin(); iter != stri.end(); iter++){
                            if( *iter > '9' || *iter < '0'){
                                        success = 0;
                                        break;
                            }
                }

                if(!success){
                    break;
                }

                vali = atoll(stri.c_str());
                if(flagi < 0){
                        vali = 0 - vali;
                }
#ifdef DEBUG
                COUT << "vali = " << vali << endl;
#endif                
                if(vali > valb || vali < vala){
                    success = 0;
                    break;
                }
            }while(0);       
            COUT << ( success ? "YES" : "NO") << endl;
        }
    return 0;
}



