/**
 * @brief jiu du 1386
 * @file 1386.cpp
 * @author mianma
 * @created 2014/01/19 18:35
 * @edited  2014/01/19 18:35
 * @type binary search
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

#define MAXSIZE 1000010
#define MAXVAL  10000010
 
int elementTots;
int elements[MAXSIZE];
 
int main()
{
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    while( CIN >> elementTots && elementTots > 0){
        for(int pos = 0; pos < elementTots; pos++){
            CIN >> elements[pos];
        }
        int ans = MAXVAL;
        int lftPos = 0;
        int rhtPos = elementTots - 1;

        if(elements[lftPos] < elements[rhtPos]){
                                    /*solve: 1 2 3 4 5 */
                ans = elements[lftPos];
        }else{
            while(rhtPos - lftPos > 1){
                int midPos = lftPos + ( (rhtPos - lftPos) >> 1);
                if(elements[midPos] >  elements[lftPos]){
                        lftPos = midPos;
                }else if(elements[midPos] < elements[rhtPos]){
                        rhtPos = midPos;
                }else{
                    /*we can't binary search when three nums all the same*/
                    for(int pos = lftPos; pos <= rhtPos; pos++)
                        ans = min(elements[pos], ans);
                    break;
                }
            }
        }
        if(MAXVAL == ans)           /*solve 5 4 3 2 1*/
            ans = min(elements[rhtPos], elements[elementTots - 1]);
        COUT << ans << "\n";
    }
    return 0;
}
