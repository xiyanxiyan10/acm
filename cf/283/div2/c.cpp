/**
 * @brief Codeforces Round #283 (Div. 2) c
 * @file c.cpp
 * @author mianma
 * @created 2014/12/21 14:17
 * @edited  2014/12/21 14:17
 * @type brute math backtracking
 * @note
 * 	c0 n + c1 n + c2n .. + cn n = 2^n
 * @TODO 
 * 	TL
 */
#include <fstream>
#include <iostream>
#include <cstring>

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

#define MAXN 1010

char table[MAXN][MAXN];     /*store input string*/
int  record1[MAXN];	    /*record string idx which is the same with the prev one*/
int  record2[MAXN];	    /*store record status wait to recover*/
int n, m;

int *curr = record1;
int *old  = record2; 
int ans = MAXN;


/**
 * @brute all possible answer
 * @param[in] tot how many col selected 
 * @param[in] free col group start  idx
 *
 */
void brute(int tot, int start){
    int row, col, ch, i;
    if(m == start){
	ans = min(ans, m - tot);
	return;
    }

    for(col = start; col < m; col++){
	int fail = 0;
	ch  = table[0][col];
	memcpy(old, curr, n*sizeof(int));		/*save status*/
	for(row = 1; row < n; row++){
	    if( 0 == curr[row]){
            	if(table[row][col] < ch){
                    	fail = 1;
			break;
		}else if(table[row][col] > ch){
		    	curr[row] = 1;
		}else{
		    	;
		}
	    }
            	ch = table[row][col];
         }
	if(1 != fail){
        	brute(tot + 1, col + 1);
	}
	int *swap = curr;				/*recover status*/
	curr = old;
	old = swap;
    }
}

int main(void){
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w", stdout);
#endif
    int ch;
    scanf("%d%d", &n, &m);
    /*faster IO*/
    for(int i = 0; i < n; i++)
    	scanf("%s", table[i]);
    brute(0, 0);
    printf("%d\n", ans == MAXN ? m : ans);
    return 0;
}



