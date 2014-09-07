#include <iostream>
#include <fstream>

using namespace std;

#ifndef DEBUG
#define CIN cin
#define COUT cout
#else
ifstream in;
ofstream out;
#define CIN in
#define COUT out
#endif



/**double cmp func*/

int main()
{
    double h, u, d, f, mv;
    while(CIN >> h >> u >> d >> f && h){
    		f = 1/f;
    		int tot_day = 1;
    		while(u - d >= 0.0 || h > 0.0){
			 h -= (u - d);
		 	 u *= f;
	 		 tot_day++;		 
		}
		/**output format rebuild*/
		if(u - d >= 0.0){
			COUT << "success ";
		}else{
			COUT << "fail";
		}
		COUT << tot_day << endl;
		
    }

    return 0;
}



