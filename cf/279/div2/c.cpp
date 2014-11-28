/**
 * @brief Codeforces Round #279 (Div. 2) c
 * @file c.cpp
 * @author 面码
 * @created 2014/11/28 17:06
 * @edited  2014/11/28 18:24
 * @type math
 * @TODO test
 * @note
 */
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

#define max(a, b)  ((a) > (b) ? (a) : (b))
#define min(a, b)  ((a) > (b) ? (b) : (a)) 
#define abs(a)     ((a) >  0  ? (a) : (0 - (a)))
#define CLR(vec)   memset(vec, 0, sizeof(vec))

#define MAXN 1000010

#ifdef DEBUG
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#else
#define CIN cin
#define COUT cout
#endif

int num[MAXN];           /*store big num */
int record[MAXN];        /*division pos record*/

int idx;
int i;
int lft, rht;
int size;
int val;
int base;
int tmp;
string str;

int main(void){
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    CIN >> str;
    CIN >> lft >> rht;

    size = str.size();

    /*check str*/
    if('0' == str[0] || size < 2){
        COUT << "NO\n";
        return 0;
    }

    for(int i = 0; i < size; i++)
            num[i] = str[i] - '0';
    
    idx = -1;

    /*calculate all lft big num division */
    val = 0;
    for(int pos = 0; pos < size; pos++){ 
        val = val*10 + num[pos];
        if(val < lft)                       /*too small, go on*/
                continue;

        tmp = val%lft;
        if(!tmp){
	       /*ignore rht str start with 0*/
	       if(pos < size - 1 && 0 == num[pos + 1])
		       		continue;
#ifdef DEBUG
		COUT << "lft: " << pos << "->" << num[pos] << "\n";
#endif
            record[pos] = 1;                /*record lft string pos*/
	 }
    }
    record[size - 1] = 0;		    /*we clear 0 end here*/

    val = 0;
    /*calculate all rht big num division*/
    for(int pos = 0; pos < size; pos++){ 
        val = val*10 + num[pos];
        if(val < rht)                       /*too small, go on*/
                continue;

        tmp = val%rht;
        if(!tmp){
#ifdef DEBUG
		COUT << "rht: " << pos << "->" << num[pos] << "\n";
#endif
            if(record[pos])
                idx = pos;
        }else{
            if(pos == size - 1)
                idx = -1;
        }
    }

    if(idx > 0){
        cout << "YES\n";
        COUT << str.substr(0, idx + 1) << " " << str.substr(idx + 1);
    }else{
        COUT << "NO\n";
    }
    return 0;
}



