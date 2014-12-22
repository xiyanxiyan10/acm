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
#include <vector>

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

#define MAXN 110

char table[MAXN][MAXN];     /*store input string*/
int record[MAXN][MAXN];     /*record row status */
int n, m;
int ans = MAXN;

#ifdef DEBUG
vector<int> db;         /*record col selected*/
#endif

/**
 * @brute all possible answer
 * @param[in] tot how many col selected 
 * @param[in] free col group start  idx
 * @param[in] old  record the char the same with the prev row
 *
 */
void brute(int tot, int start, int *old, int old_cnt){
    int row, col, missmatch;
    int buf[MAXN];
    int *curr = buf; 
    if(m == start){
#ifdef DEBUG
        printf("tot %d\n", tot);
        printf("path: ");
        for(int i = 0; i < db.size(); i++)
            printf("%d->", db[i]);
        printf("\n");
#endif
	ans = min(ans, m - tot);
	return;
    }

    for(col = start; col < m; col++){
	int curr_cnt  = 0;
	missmatch = 0;
	for(int i = 0; i < old_cnt; i++){
	    row = old[i];
            if(record[row][col] < 0){
                    missmatch = 1;
		    break;
	    }else if(record[row][col] > 0){
	            ;  
	    }else{
	        curr[curr_cnt++] = row;
	    }
        }
	if(!missmatch){
#ifdef DEBUG
                db.push_back(col);
#endif
        	brute(tot + 1, col + 1, curr, curr_cnt);
#ifdef DEBUG
                db.erase(db.end() - 1);
#endif  
	}
    }
}

int main(void){
#ifdef DEBUG
    freopen("./in", "r", stdin);
    freopen("./out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    	scanf("%s", table[i]);
    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            record[i][j] = table[i][j] - table[i - 1][j];
    int buf[MAXN];
    int *old = buf;
    int old_cnt = 0; 
    for(int i = 1; i < n; i++)
        old[old_cnt++] = i;
    brute(0, 0, old, old_cnt);
    printf("%d\n", ans == MAXN ? m : ans);
    return 0;
}



