#include <stdio.h>
#include <string.h>

#define MAXN 100010
#define MAXK 15


#define CLR(vec) memset(vec, 0, sizeof(vec))


struct point{
    int id;
    int pos;
}table[MAXN];

double val[MAXN];       /*val  of the id*/
int knn[MAXN][MAXK];    /*nearest k pos for id*/


static void build_one_knn(struct point *tb, int idx, int n, int k)
{
    int lidx = idx - 1;
    int ridx = idx + 1;
    int cnt  = 0;
    int pos  = tb[idx].pos;

    while(cnt < k){
        do{
            if(lidx < 0){
                knn[idx][cnt] = tb[ridx++].id;
                break;
            }

            if(ridx >= n){
                knn[idx][cnt] =  tb[lidx--].id;
                break;
            }

            int flag = (tb[ridx].pos - pos) - (pos - tb[lidx].pos);
                
            if(flag < 0){
                knn[idx][cnt] =  tb[ridx++].id;
            }else if (flag > 0){
                knn[idx][cnt] =  tb[lidx--].id;
            }else{
                if(tb[ridx].id < tb[lidx].id){
                    knn[idx][cnt] = tb[ridx++].id;
                }else{
                    knn[idx][cnt] =  tb[lidx--].id;
                }
            }
        }while(0);
        cnt++;
    }
}

static void build_knn(int n, int k)
{
    int i, j, idx;
    struct point element;
    for(i = 0; i < n; i++){
            scanf("%d%lf", &(element.pos), &val[i]);
            element.id = i + 1;         /*Notice:element.id = real id + 1*/
            for(j = i - 1; j >= 0 && table[j].pos > element.pos; j--){
                            table[j + 1] = table[j];
            }
            table[j + 1] = element;
    }
    for(idx = 0; idx < n; idx++)
            build_one_knn(table, idx, n, k);
}


int  main(void)
{
#ifdef DEBUG
      freopen("in", "r", stdin);
      freopen("out","w", stdout);
#endif
      int cases, currCase;
      double ans, tmp;
      int n, m, k, cnt, qidx;
      scanf("%d", &cases);
      for(currCase = 1; currCase <= cases; currCase++){
                CLR(table);
                CLR(knn);
                CLR(val);
                scanf("%d%d%d", &n, &m, &k);
                ans = 0.0;
                build_knn(n, k);    


#ifdef DEBUG
        int i, j;
        printf("printf nearest pos\n");
        for(i = 0; i < n; i++){
                printf("%d -> ", i);      
                j = 0;
                while(0 != knn[i][j]){
                    printf("%d ", knn[i][j] - 1);      
                    j++;
                }
                printf("\n");
        }
#endif

                while(m--){
                    tmp = 0.0;
                    scanf("%d", &qidx);
                    cnt = 0;
                    while(0 != knn[qidx - 1][cnt]){
                            tmp += val[knn[qidx - 1][cnt] - 1];
                            cnt++;
                    }
                    tmp /= cnt;
                    ans += tmp;
                    val[qidx - 1] = tmp;
                }
                printf("%.6lf\n", ans);
      }
    return 0;
}



