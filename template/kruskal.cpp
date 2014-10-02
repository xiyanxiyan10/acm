
/*
 * @brief kruskal 算法
 * @file  kruskal.cpp
 * @author xiyanxiyan10
 * @CreatedTime 2014/10/02
 * @LastChanged 2014/10/02
 * @note 最小声称树的克鲁斯卡尔解法
 */

#include <vector>
#include <iostream>
#include <algorithm>


namespace sptree{
using namespace std;
class Edge{
    public:
        int lft;
        int rht;
        int weight;
};
struct edgeComapre {
      bool operator() (Edge lft, Edge rht) { return (lft.weight < rht.weight);}
} edgeCompareObj;
class Kruskal{
    public:
        Kruskal(void):tot(0) { tmpClean(); }
        int init(const int &posSize);
        int insert(const class Edge nedge);
        int build(void);
        virtual ~Kruskal(void){ tmpClean();  }
    private:
        void tmpClean(void);
        int findSet(const int &pos);
        void makeUnion(const int &lft, const int &rht);
        vector<class Edge> edges;
        int *fatherA;
        int  posSize;
        int tot;
};

int Kruskal::insert(const class Edge nedge) {
        if(nedge.lft >= posSize || nedge.rht >= posSize)
            return - 1;
        edges.push_back(nedge);
        return 0;
}

void Kruskal::tmpClean(){
        edges.clear();
        if(fatherA){
            delete  fatherA;
            fatherA = NULL;
        }
}

int Kruskal::findSet(const int &pos){
    int rootPos;
    int currPos = pos;
    while(fatherA[currPos] != currPos){
        currPos = fatherA[currPos];
    }
    rootPos = currPos;
    currPos = pos;
    while(currPos != rootPos){
            int fatherPos = fatherA[currPos];
            fatherA[currPos] = rootPos;
            currPos = fatherPos;
    }
    return rootPos;
}

int Kruskal::init(const int &iposSize){
    if(iposSize <= 0)
            return -1;
    posSize = iposSize;
    if( NULL == ( fatherA = new int[posSize])){
            return -1;
    }

    for(int currPos = 0; currPos  < posSize; currPos++){
            fatherA[currPos] = currPos;
    }
    return 0;
}

int Kruskal::build(void){
    int ret = 0;
    sort(edges.begin(), edges.end(), edgeCompareObj);
    for(vector<class Edge>::iterator iter =  edges.begin(); iter != edges.end(); iter++){
            int lftRoot = findSet(iter->lft);
            int rhtRoot = findSet(iter->rht);
            if(lftRoot == rhtRoot){
                continue;
            }
            makeUnion(lftRoot, rhtRoot);
            ret += iter->weight;
    }
    tmpClean();
    return ret;
}

void Kruskal::makeUnion(const int &lft, const int &rht){
        fatherA[lft] = rht;
}
}

using namespace sptree;
int main(){
    class Kruskal *krup  = new class Kruskal;
    class Edge nedge;
    if(!krup){
            cout << "new kruskal fail" << endl;
            return -1;
    }
    if(krup->init(20) < 0){
        cout << "set max pos fail" << endl;
        return -1;
    }
    cout << "please input info for every edge" << endl;
    while(cin >> nedge.lft >> nedge.rht >> nedge.weight){
                    krup->insert(nedge);
                    cout << "please input info for every edge" << endl;
    }
    cout << krup->build() << endl;
    return 0;
}
