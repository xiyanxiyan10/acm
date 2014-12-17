/**
 * @brief live archive 3401
 * @file 3401.cpp
 * @author mianma
 * @created 2014/12/17 15:09
 * @edited  2014/12/17 15:09
 * @type 
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
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

#define MAXV        6
#define MAXN        4
#define MAXB        24

/*if cube rot left, 0, 1, 2, 3, 4, 5 -> 1, 5, 2, 3, 0,  4*/
int lft[] = { 1, 5, 2, 3, 0, 4};
/*if cude rot up,   0, 1, 2, 3, 4, 5 -> 3, 1, 0, 5, 4,  2*/
int up[] =  { 3, 1, 0, 5, 4, 2};


/*rot*/
void rot(int *dir, int *base){
    int tmp[MAXV];
    memcpy(tmp, base, sizeof(tmp));
    for(int i = 0; i  < MAXV; i++)
            base[i] = tmp[dir[i]];
}

int dice[MAXB][MAXV];
int table[MAXN][MAXV];

/*brute all status*/
void brute(){
    int view = 0;
    int tmp[MAXV];
    int base[MAXV] = { 0, 1, 2, 3, 4, 5};
    for(int i = 0; i < MAXV; i++){
        memcpy(tmp, base, sizeof(tmp));
        if(0 == i){ 
            rot(up, tmp);  
        
        }
        if(1 == i){ 
            rot(lft, tmp); 
            rot(up, tmp); 
        }
        if(2 == i){ ;}
        if(3 == i){ rot(up, tmp); rot(up, tmp); }
        if(4 == i){ rot(lft, tmp); rot(lft, tmp); rot(lft, tmp); rot(up, tmp); }
        if(5 == i){ rot(lft, tmp); rot(up, tmp); }
        for(int j = 0; j < 3; j++){
            memcpy(dice[view++], tmp, sizeof(tmp));
            rot(lft, tmp);
            view++;
        }
    }
}

vector<string> db;

void db_init(){
    db.clear();
}

int db_add(string color){
    int i;
    for(i = 0; i < db.size(); i++)
        if(db[i] == color)
                return i;
    db.push_back(color);  
    return i;
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    /*init status table*/
    brute();
    /*read input and solve problem*/

    return 0;
}



