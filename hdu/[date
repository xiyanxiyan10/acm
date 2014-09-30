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
}table[MAXN];

double val[MAXN];       /*val  of the id*/
int knn[MAXN][MAXK];    /*nearest k pos for id*/


static void inline sort_bypos(struct point *tb, int n){
    for(int i = 1; i < n; i++){
            struct point tmp = tb[i];  
            int j;
            for(j = i - 1; j > 0 && tb[j].pos > tmp.pos; j--){
                           tb[j + 1] = tb[j];
            }
            tb[j + 1] = tmp;
    }
}


static void inline build_one_knn(struct point *tb, int idx, int n, int k)
{
    int lidx = idx - 1;
    int ridx = idx + 1;
    int cnt  = 0;
    int pos  = tb[idx].pos;
    while(cnt < k){
        do{
            if(lidx < 1){
                knn[idx][cnt] = tb[ridx].id;
                ridx++;       
                break;
           }

            if(ridx > n){
                knn[idx][cnt] =  tb[lidx].id;
                lidx--;
                break;
            }

            int flag = (tb[ridx].pos - pos) - (pos - tb[lidx].pos);
                
            if(flag < 0){
                knn[idx][cnt] =  tb[ridx].id;
                ridx++;       
                break;
            }else{
                knn[idx][cnt] =  tb[lidx].id;
                lidx--;
                break;
            }

        }while(0);
        cnt++;
    }
}

static void inline build_knn(int n, int k)
{
    for(int i = 1; i <= n; i++){
            scanf("%d%lf", &table[i].pos, &val[i]);
            table[i].id = i;
    }
    /*sort by pos*/
    sort_bypos(table + 1, n);
    for(int i = 1; i <= n; i++)
            build_one_knn(table, i, n, k);
}


int  main(void)
{
#ifdef DEBUG
      freopen("in", "r", stdin);
      freopen("out","w", stdout);
#endif
      int cases;
      int n, m, k;
      scanf("%d", &cases);
      for(int currCase = 1; currCase <= cases; currCase++){
                CLR(table);
                CLR(knn);
                CLR(val);
                scanf("%d%d%d", &n, &m, &k);
                double ans = 0.0;
                build_knn(n, k);    
                while(m--){
                    double tmp = 0.0;
                    int qidx;           
                    scanf("%d", &qidx);
                    int cnt = 0;
                    while(0 != knn[qidx][cnt]){
                            tmp += val[knn[qidx][cnt]];
                            cnt++;
                    }
                    tmp /= cnt;
                    ans += tmp;
                    val[qidx] = tmp;
                }
                printf("%.6lf\n", ans);
      }
    return 0;
}



