#include <iostream>
#include <fstream>

using namespace std;


#define FLOAT_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))

#define DEUG
#ifdef DEBUG

ifstream in;
ofstream out;
#define CIN in
#define COUT out
int init_debug(void){
	in.open("./in", ios::in);
	out.open("./out", ios::out);
	if(in.fail() && out.fail()){
		return -1;
	}
	return 0;
}

#else

#define CIN cin
#define COUT cout
#endif




/**double cmp func*/

int main()
{
#ifdef DEBUG
	init_debug();
#endif
    double h, u, d, f;
    while(CIN >> h >> u >> d >> f && h){
    		f = u*f/100.0;
		double curr = 0.0;
    		int tot_day = 1;
    		while(1){
#ifdef DEBUG
	    		cout << " curr = " << curr << " h =" << h << " u=" << u << " d= " << d << " f= ";
		       	cout << f << " day= " << tot_day<< endl;
#endif
			 curr += u;
			 if(curr > h){
			    break;
			 }

			 curr -= d;

			 if(curr <  0.0)
				 break;
		 	 
			 u = u < f ? 0.0 : u - f;

	 		 tot_day++;		 
		}
		/**output format rebuild*/
		if(curr >= h){
			COUT << "success on day ";
		}else{
			COUT << "failure on day ";
		}
		COUT << tot_day << endl;
#ifdef DEBUG
		cout << endl;
#endif	
    }
    return 0;
}



