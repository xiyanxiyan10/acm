/**
 * @brief jiu du 1511
 * @file 1511.cpp
 * @author mianma
 * @created 2014/01/20 14:54
 * @edited  2014/01/20 14:54
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

struct list{
    int val;
    struct list *next;
    list(const int &val, struct list *next){
        this->val = val;
        this->next = next;
    }
};

struct list *head = NULL;
struct list *curr = NULL;

void print_list(struct list *clist){
    if(!clist)
        return;
    print_list(clist->next);
    if(clist != head)
        COUT << clist->val << "\n";
}

void delete_list(struct list *clist){
    if(!clist)
        return;
    delete_list(clist->next);
    delete clist;
}

int main()
{
    //ios_base::sync_with_stdio(0);
#ifdef DEBUG
    CIN.open("./in",  ios::in);
    COUT.open("./out",  ios::out);
#endif
    int val;
    while(CIN >> val){
            if(!head){
                head = new list(0, NULL);   
                curr = head;
            }
        
            if(val < 0){
                print_list(head);
                delete_list(head);
                head = NULL;
            }else{
                /*alloc new head when new test start*/
                struct list *nlist = new list(val, NULL);
                curr->next = nlist;
                curr  = nlist;
            }
    }
    return 0;
}
