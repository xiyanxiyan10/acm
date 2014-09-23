#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

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


#define MAXN 100010
#define MAXK 15


#define CLR(vec) memset(vec, 0, sizeof(vec))


struct point{
    int id;
    int pos;
    double val;
    int knn[MAXK];    
    int cnt;
};

struct point table[MAXN];


void sort_byid(struct point *tb, int n){
    for(int i = 1; i < n; i++){
            struct point tmp = tb[i];  
            int j;
            for(j = i - 1; j > 0 && tb[j].id > tmp.id; j++){
                           tb[j + 1] = tb[j];
            }
            tb[j] = tmp;
    }
}


void sort_bypos(struct point *tb, int n){
    for(int i = 1; i < n; i++){
            struct point tmp = tb[i];  
            int j;
            for(j = i - 1; j > 0 && tb[j].pos > tmp.pos; j++){
                           tb[j + 1] = tb[j];
            }
            tb[j] = tmp;
    }
}


void build_one_knn(struct point *tb, int idx, int n, int k)
{
    int lidx = idx - 1;
    int ridx = idx + 1;
    int *cntp = &tb[idx].cnt;
    int pos  = tb[idx].pos;
    while(*cntp < k){
        do{
            if(lidx < 0){
                tb[idx].knn[*cntp++] = tb[ridx].id;
                ridx++;       
                break;
           }

            if(ridx >= n){
                tb[idx].knn[*cntp++] =  tb[lidx].id;
                lidx--;
                break;
            }

            int flag = (tb[idx].pos - pos) - (pos - tb[idx].pos);
                
            if(flag < 0){
                tb[idx].knn[*cntp++] =  tb[ridx].id;
                ridx++;       
                break;
            }else{
                tb[idx].knn[*cntp++] =  tb[lidx].id;
                lidx--;
                break;
            }

        }while(0);
    }
}

void build_knn(int n, int k)
{
    for(int i = 0; i < n; i++){
            scanf("%d%lf", &table[i].pos, &table[i].val);
            table[i].id = i;
    }
    /*sort by pos*/
    for(int i = 0; i < n; i++)
            build_one_knn(table, i, n, k);
    /*sort by id*/
}


int  main(void)
{
#ifdef DEBUG
      freopen("in", "r", stdin);
      freopen("out","w", stdout);
      strinag buffer;
      CIN.open("in", ios::in);
      COUT.open("out", ios::out);
      while(getline(CIN, buffer))
            COUT << buffer << "\n";
      COUT << "Out Put" << "\n";
      CIN.close();
      CIN.open("in", ios::in);
#endif
      int cases;
      int n, m, k;
      scanf("%d", &cases);
      for(int currCase = 1; currCase <= cases; currCase++){
                CLR(table);
                CIN >> n >> m >> k;
                double ans = 0.0;
                build_knn(n, k);    
                while(k--){
                    double tmp = 0.0;
                    int qidx;           
                    scanf("%d", &qidx);
                    qidx--;
                    int cnt = 0;
                    for(int i  = 0; i < table[qidx].cnt; i++){
                            int j = table[qidx].knn[i];
                            tmp += table[j].val;
                            cnt++;
                    }     
                    tmp /= cnt;
                    ans += tmp;
                    table[qidx].val = tmp;
                }
                printf("%.6lf\n", ans);
      }
    return 0;
}



