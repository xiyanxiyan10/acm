#include <iostream>
#include <fstream>

using namespace std;

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



int main()
{
#ifdef DEBUG
	init_debug();
#endif
    int m, n;
    while(CIN >> m >> n && m && n)
                COUT << m*n -1 << endl;
	return 0;
}



