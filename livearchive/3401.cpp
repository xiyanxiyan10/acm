/**
 * @brief live archive 3401
 * @file 3401.cpp
 * @author mianma
 * @created 2014/12/18 9:23
 * @edited  2014/12/18 9:23
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

vector<string> db;
int dice[MAXB][MAXV];
int table[MAXN][MAXV];
int status[MAXN];
int n;
int ans;

/*brute all status*/
void brute(void){
    int view = 0;
    int tmp[MAXV];
    int base[MAXV] = { 0, 1, 2, 3, 4, 5};
    for(int i = 0; i < MAXV; i++){
        memcpy(tmp, base, sizeof(tmp));
        if(0 == i){ rot(up, tmp);  }
        if(1 == i){ rot(lft, tmp); rot(up, tmp); }
        if(2 == i){ ;}
        if(3 == i){ rot(up, tmp); rot(up, tmp); }
        if(4 == i){ rot(lft, tmp); rot(lft, tmp); rot(lft, tmp); rot(up, tmp); }
        if(5 == i){ rot(lft, tmp); rot(lft, tmp); rot(up, tmp); }
        for(int j = 0; j < 4; j++, view++){
            memcpy(dice[view], tmp, sizeof(tmp));
            rot(lft, tmp);
        }
    }
}

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

/*try to get better answer*/
void check_ans()
{
    /*counter difference color*/
    int counter[MAXB];
    int tot = 0;
    for(int i = 0; i < MAXV; i++){
        CLR(counter);   
        int max_faces = 0;
        for(int j = 0; j < n; j++){
            int tmp = ++counter[table[j][dice[status[j]][i]]];
            max_faces = max(max_faces, tmp);
        }
        tot += n - max_faces;   
    }
    ans = min(tot, ans);
}

void dfs(int d){
    if(d == n )
        check_ans();
    else{
        for(int i = 0; i < MAXB; i++){
            status[d] = i;
            dfs(d + 1);
        }
    }   
}

int main(void){
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    string color;
    /*init status table*/
    brute();
#ifdef DEBUG
    for(int i = 0; i < MAXB; i++){
        for(int j = 0; j < MAXV; j++)
                COUT << dice[i][j] << " ";
        COUT << "\n";
    }
#endif
    while(CIN >> n && n){
    /*init color db*/
        db_init();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < MAXV; j++){
                CIN >> color;
                table[i][j] = db_add(color);
            }
#ifdef DEBUG
    /*decode color*/
        for(int i = 0; i < n; i++){
            for(int j = 0; j < MAXV; j++){
                COUT << db[table[i][j]] << " ";
            }
            COUT << "\n";
        }
#endif
        ans = n*MAXV;
        status[0] = 2;
        dfs(1);
        COUT << ans << "\n";
    }
    return 0;
}



