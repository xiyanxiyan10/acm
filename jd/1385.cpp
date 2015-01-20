/**
 * @brief jiu du 1384
 * @file 1384.cpp
 * @author mianma
 * @created 2014/01/20 14:16
 * @edited  2014/01/20 14:16
 * @type 
 * @note
 */
#include <fstream>
#include <iostream>
#include <string>

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

#define MAXN 1100
int pre_table[MAXN];
int mid_table[MAXN];
int next_table[MAXN];
struct node{
    struct node *lft;
    struct node *rht;
    int val;
    node(const int &val){
        this->lft = NULL;
        this->rht = NULL;
        this->val = val;
    }
}; 

struct node *head;

int n;

int search_pos(const int *vec, const int &size, const int &val){
    for(int i = 0; i < size; i++)
        if(vec[i] == val)
            return i;
    return -1;
}

/*status mark wether build tree fail, go into with status == 1*/
struct node *build_tree(const int *pre, const int *mid, const int size, int &status){
    struct node *lft, *rht, *ret; 
    if(0 == status)
        return NULL;
    if(0 == size){
        return NULL;
    }
    if(1 == size){
        /*we check leaf conflict here*/
        if(pre[0] != mid[0]){   
            status = 0;
            return NULL;
        }else{
            return (new  node(pre[0]));
        }
    }
    int val = pre[0];
    /*we check node conflict here*/
    int pos = search_pos(mid, size, val);
    if(pos < 0){
        status = 0;
        return NULL;
    }
    int lft_size = pos;
    int rht_size = size - pos - 1;
    lft = build_tree(pre + 1, mid, lft_size, status);
    rht = build_tree(pre + 2 + lft_size, mid + 1 + lft_size, rht_size, status);
    if(0 == status)
        return NULL;
    if( (!lft && lft->val >= val) || (!rht && rht->val <= val)){
        status = 0;
        return NULL;
    }
    ret = new  node(val);
    ret->lft = lft;
    ret->rht = rht;
    return ret;
}

void visit_tree(struct node *n, int *ans){
    if(!n)  return;
    

}

int main()
{
    //ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    while(CIN >> n && n){
        for(int i = 0; i < n; i++)
            CIN >> pre_table[i];
        for(int i = 0; i < n; i++)
            CIN >> mid_table[i];
    
    }
    return 0;
}
