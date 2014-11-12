

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

const int MAXN = 10;

/**
 * @brief 	str the str wait to convert
 * @len   	len of the str wait to convert tot ll int
 * @success 	check input valid
 * @return      convert num when success, random num when fail
 *
 */
 long long int str_to_ll(const char *str, const unsigned int len, int *success){
	 long long int val;	/*convert val*/
	 const char *p;		/*str start*/
	 int left;		/*left size*/
	 int cnt;		/*used for count*/
	 *success = 0;		/*default fail*/
	 val = 0;

	 if(len < 1)		/*string too small*/
		return val;
	 
	 left = len;
	 p    = str;

	 if(*p == '-'){		/*start with '-' ?*/
	 	p++;
		left--;
		if(0 == left)                   /*-*/
			return val;
		if( *p <= '0' || *p >= '9')	/*-0 or -[a-f...]*/	
			return val;
	 }else if(*p >= '0' && *p <= '9'){      /*start with num*/
		if(left > 1 && '0' == *p)       /*0XXX*/
			return val;

	 }else                                  /*start with char*/
		 return val;
#if 0
        COUT << p << endl;
#endif
	 val = 0;
	 while(left && *p >= '0' && *p <= '9'){
		val = 10*val + (*p - '0'); 
	 	left--;
		p++;
	 }
	 if(left)
		 return val;
	 
	 val = (*str == '-' ? (0 - val) : val);   /*convert success*/
	 *success = 1;
	 return val;
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
        int success;

        string stri;
        string stra;
        string strb;

        long long int vali;
        long long int vala;
        long long int valb;


        while(CIN >> stri >> stra >> strb){
            do{
                vali = str_to_ll(stri.c_str(), stri.size(), &success);
#ifdef DEBUG
                COUT << stri << "->" << vali << endl;
#endif

                if(!success)
                    break;

                vala = str_to_ll(stra.c_str(), stra.size(), &success);
#ifdef DEBUG
                COUT << stra << "->" << vala << endl;
#endif
                if(!success)
                    break;

                valb = str_to_ll(strb.c_str(), strb.size(), &success);
#ifdef DEBUG
                COUT << strb << "->" << valb << endl;
#endif
                if(!success)
                    break;

                if(vali <= valb && vali >= vala)
                    success = 1;
            
            }while(0);   
            COUT << ( success ? "YES" : "NO") << endl;
        }
    return 0;
}



