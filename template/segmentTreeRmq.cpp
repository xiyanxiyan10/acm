
/*
 * @brief 线段树算法解决RMQ问题
 * @file segmentTreeRmq.cpp
 * @author xiyan
 * @CreatedTime 2014/10/02
 * @LastChanged 2014/10/02
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
namespace rmq
{
using namespace std;
typedef unsigned int size_t;
typedef signed   int ssize_t;
static ssize_t inline  getLftNode(const ssize_t idx)
{
    return (idx << 1);
}
static ssize_t inline  getRhtNode(const ssize_t idx)
{
    return ((idx << 1) + 1);
}
template<typename T>
class segmentTree
{
public:
    segmentTree(void):deps(0), nodes(0), elems(0), tree(NULL) {}
    ssize_t createSt(const T *input, const ssize_t cnt);
    ~segmentTree(void)
    {
        destorySt();
    }
    const T * searchSt(const ssize_t lftQuery, const ssize_t rhtQuery);
    virtual void debug(void);
private:
    ssize_t allocSt(const ssize_t cnt);
    ssize_t initSt(const T *input);
    ssize_t initNode(const ssize_t nodeIdx, const ssize_t lftIdx, const ssize_t rhtIdx, const T *input);
    const T *searchNode(const ssize_t nodeIdx, const ssize_t lftIdx, const ssize_t rhtIdx, \
                        const ssize_t lftQuery, const ssize_t rhtQuery);
    void destorySt(void);
    ssize_t log(const ssize_t x) const;
    bool checkPow(const ssize_t x) const;
    T *tree;
    ssize_t deps;                                 /*dep of the tree*/
    ssize_t nodes;                                /*nodes tots*/
    ssize_t elems;                                /*element tots*/
};
/**
 * @brief 2^n <= x, return n;
 * @return n success, -1 fail
 *
 */
template<typename T>
ssize_t segmentTree<T>::log(const  ssize_t x) const
{
    ssize_t ans  = 0;
    ssize_t cnt = x;
    if(cnt <= 0)
    {
        return -1;
    }
    while( (1 << ans) <= cnt)
    {
        ++ans;
    }
    ans--;
    return ans;
}
/**
 * @brief make sure the input is pow of 2
 * @return n success, -1 fail
 *
 */
template<typename T>
bool segmentTree<T>::checkPow(const  ssize_t x) const
{
    if(x <= 0)
    {
        return false;   /*x <= 0*/
    }
    if(!(x & (x - 1)))
    {
        return true;    /*x == 2^n*/
    }
    else
    {
        return false;   /*x > 0 && x != 2^n*/
    }
}
/**
 * @brief get the dep and the size for tree
 * @param[in] cnt tots of the input to build tree
 *
 */
template<typename T>
ssize_t segmentTree<T>::allocSt(const ssize_t cnt)
{
    if(cnt <= 0)
    {
        return -1;
    }
    ssize_t depTmp = log(cnt);
    if(depTmp < 0)
    {
        return -1;
    }
    if(!checkPow(cnt))
    {
        depTmp++;
    }
    depTmp++;
    ssize_t nodeTots = (1 << depTmp) - 1;   /*nodes needed */
    nodeTots++;                             /*add empty node at head*/
    tree = new T[nodeTots];
    if(!tree)
    {
        return -1;
    }
    memset(tree, 0, nodeTots);
    deps   = depTmp;                      /*store cnt*/
    nodes  = nodeTots;
    elems  = cnt;
    return 0;
};
/**
 * @brief init tree
 *
 */
template<typename T>
ssize_t segmentTree<T>::initSt(const T *input)
{
    const ssize_t rootNode = 1;
    const ssize_t lftIdx   = 0;
    const ssize_t rhtIdx   = elems - 1;
    if(initNode(rootNode, lftIdx, rhtIdx, input) < 0)
    {
        return -1;
    }
    return 0;
}
/**
 * @brief init node and continue to build children
 * @param[in] nodeIdx curr node
 * @param[in] lftIdx start idx for input
 * @param[in] rhtIdx end idx  for input
 * @param[in] store for input
 * @return -1 error
 *         0  success
 */
template<typename T>
ssize_t segmentTree<T>::initNode(const ssize_t nodeIdx, const ssize_t lftIdx, const ssize_t rhtIdx, const T *input)
{
    //cout << "nodeIdx = " << nodeIdx << "," << "nodes =" << nodes << endl;  
    cout << lftIdx << " "<< rhtIdx << endl;
    if(nodeIdx >= nodes)     /*segment error*/
    {
        return -1;
    }
    if(lftIdx == rhtIdx)
    {
        tree[nodeIdx] = input[lftIdx];
        return 0;
    }
    ssize_t midIdx = (lftIdx + rhtIdx) >> 1;
    ssize_t curNode = nodeIdx;
    ssize_t lftNode = getLftNode(curNode);
    ssize_t rhtNode = getRhtNode(curNode);
    if(initNode(lftNode, lftIdx, midIdx, input) < 0)
    {
        return -1;
    }
    if(initNode(rhtNode, midIdx + 1, rhtIdx, input) < 0)
    {
        return -1;
    }
    tree[curNode] = (tree[lftNode] < tree[rhtNode] ? tree[lftNode] : tree[rhtNode]);
    return 0;
}
/**
 * @brief create segment tree
 * @param[in] input elems used to build segment tree
 * @param[in] cnt   tot nums of elems
 * @return 0 success, -1 fail
 */
template<typename T>
ssize_t segmentTree<T>::createSt(const T *input, const ssize_t cnt)
{
    if(allocSt(cnt) < 0)
    {
        cout << "alloc space for segment tree fail" << endl;
        return -1;
    }
    if(initSt(input) < 0)
    {
        cout << "init segment tree fail" << endl;
        return -1;
    }
    return 0;
}
/**
 * @brief search ans for the query range
 * @param[in] nodeIdx node index
 * @param[in] lftIdx  lft index for data store
 * @param[in] rhtIdx  rht index for data store
 * @param[in] lftQuery lft for query range
 * @param[in] rhtQuery rht for query range
 */
template<typename T>
const T * segmentTree<T>::searchNode(const ssize_t nodeIdx, const ssize_t lftIdx, const ssize_t rhtIdx, \
                                     const ssize_t lftQuery, const ssize_t rhtQuery)
{
    if(lftIdx > rhtQuery || rhtIdx < lftQuery)
    {
        return NULL;
    }
    if( lftQuery <= lftIdx && rhtQuery >= rhtIdx)
    {
        return (&tree[nodeIdx]);
    }
    ssize_t midIdx = (lftIdx + rhtIdx) >> 1;
    ssize_t curNode = nodeIdx;
    ssize_t lftNode = getLftNode(curNode);
    ssize_t rhtNode = getRhtNode(curNode);
    const T  *lftans = searchNode(lftNode, lftIdx, midIdx, lftQuery, rhtQuery);
    const T  *rhtans = searchNode(rhtNode, midIdx + 1, rhtIdx, lftQuery, rhtQuery);
    if(!lftans)
    {
        return rhtans;
    }
    if(!rhtans)
    {
        return lftans;
    }
    return (*lftans  < *rhtans ? lftans : rhtans);
}
template<typename T>
const T * segmentTree<T>::searchSt(const ssize_t lftQuery, const ssize_t rhtQuery)
{
    if(lftQuery < 0 || rhtQuery >= elems || lftQuery > rhtQuery)
    {
        return NULL;
    }
    const T *ans;
    const ssize_t rootNode = 1;
    const ssize_t lftIdx   = 0;
    const ssize_t rhtIdx   = elems - 1;
    if( NULL == (ans = searchNode(rootNode, lftIdx, rhtIdx, lftQuery, rhtQuery)))
    {
        return NULL;
    }
    return  ans;
}
/**
 * @brief destory the array for store tree
 *
 */
template<typename T>
void segmentTree<T>::destorySt(void)
{
    delete tree;
    deps = 0;
    nodes = 0;
    elems = 0;
}
/**
 * @brief debug segment tree
 *
 */
template<typename T>
void segmentTree<T>::debug(void)
{
    cout << "deps :  " << deps  << endl;
    cout << "nodes:  " << nodes << endl;
    cout << "elems:  " << elems << endl;
}
}


int main()
{

    return 0;
}
