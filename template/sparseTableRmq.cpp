/*
 * @brief sparse table 算法解决RMQ问题
 * @file sparseTableRmq.cpp
 * @author xiyan
 * @CreatedTime 2014/06/17
 * @LastChanged 2014/10/02
 */


#include <cstdlib>
#include <iostream>
#include <cmath>


namespace rmq{
using namespace std;
template<typename T>
class sparseTable{
public:
ssize_t createSt(const T *arrayPtr, const ssize_t arraySize);         
/*build st by input*/
const T *searchSt(const ssize_t startPos, const ssize_t endPos);     
/*lookup the min val from  startPos to endPos*/
virtual ~sparseTable(void);                                              
/*destory st when class destory*/
virtual void debug(void);
private:
    ssize_t allocSt(const ssize_t arraySize);               /*alloc space for st*/
    ssize_t initSt (const T *arrayPtr);                     /*init St*/
    ssize_t stLog(ssize_t size) const;                      /*make lg(size)*/   
    T * getItem(const ssize_t base, const ssize_t logTots); /*get item from sparse table*/                        
    void destorySt(void);
    ssize_t *getMaxLogTots(void){                           
        return &tot_row;
    }               
    ssize_t *getMaxBase(void){
        return &tot_col;
    }
    T *dpSt;                                                   /*sparse table*/
    ssize_t tot_row;                                           /*sparee table tot row*/
    ssize_t tot_col;                                           /*sparse table tot col */
};
/**
 * @brief deinit api for st
 * @note call destorySt to do clean task
 */
template<typename T>
void sparseTable<T>::debug(void){
    cout << "tot nums(lg):"<< *getMaxLogTots() << endl;
    cout << "tot base    :"<< *getMaxBase() << endl;
    if(dpSt){
        for(ssize_t tot = 0; tot < *getMaxLogTots(); tot++)
            for(ssize_t base = 0; base < *getMaxBase(); base++){
                cout << "Logtot " << tot;
                cout << ",";
                cout << "base " << base;
                cout << "| ->";
                cout << *getItem(base, tot) << endl;
            }
    }
}
/**
 * @brief deinit api for st
 * @note call destorySt to do clean task
 */
template<typename T>
void sparseTable<T>::destorySt(void){
    delete dpSt;
}
/**
 * @brief play as a cleaner when destory st
 *
 */
template<typename T>
sparseTable<T>::~sparseTable(void){
    destorySt();
}
/**
 * @brief 2^n <= size, return n; 
 * @return n success, -1 fail
 *
 */
template<typename T>
ssize_t sparseTable<T>::stLog(const ssize_t size) const {
    ssize_t ans  = 0;
    if(size <= 0){
        return -1;
    }
    while( (1 << ans) <= size){
        ++ans;
    }
    ans--;
    return ans;
}
/**
 * @brief create sparse Table
 * @param[in] arrayPtr base data store in array for building sparse table
 * @param[in] data tots
 * @return 0 success, -1 fail
 */
template<typename T>
ssize_t sparseTable<T>::allocSt(const ssize_t arraySize){
        ssize_t *maxBase    = getMaxBase();
        ssize_t *maxLogTots = getMaxLogTots(); 
        
        *maxBase     = arraySize;
        *maxLogTots  = stLog(arraySize);
        if( *maxLogTots < 0){
            return -1;
        }
        *maxLogTots += 1;
        ssize_t totSize = (*maxBase) * (*maxLogTots);
        dpSt = new T[totSize];
        if(NULL == dpSt){
            return -1;
        }
        return 0;
}

/**
 * @brief get Item from table 
 * @note 
 *      1. row act as totnums cnt
 *      2. col act as idx for base num
 *      3. col >= row for Table 
 */     
template<typename T>
T *sparseTable<T>::getItem(const ssize_t base, const ssize_t logTots){
    if( !dpSt || base < 0 || logTots < 0 || base >= *getMaxBase() || logTots >= *getMaxLogTots()){
                return NULL;
    }
    return (&dpSt[logTots * (*getMaxBase()) + base]);
}
/**
 * @brief init sparse Table by input 
 * @param[in] arrayPtr ptr to the imput array
 */
template<typename T>
ssize_t sparseTable<T>::initSt(const T *arrayPtr){
    for(ssize_t base = 0; base < *getMaxBase(); base++){            
            T  * itemPtr = getItem(base, 0);
            if(NULL == itemPtr){
                    return -1;
            }
            *itemPtr = arrayPtr[base];
    }
#if 0
    cout << "init phase0 success" << endl;
#endif
    for(ssize_t logTots = 1; logTots < *getMaxLogTots(); logTots++){
        for(ssize_t base = 0; ((base + (1 <<  logTots) ) <= (*getMaxBase())); base++){  
            T *lItem = getItem(base, logTots - 1); 
            T *rItem = getItem(base + (1 << (logTots - 1)), logTots - 1);
            T *cItem = getItem(base, logTots);
            if(NULL == lItem || NULL == rItem|| NULL == cItem){
                return -1;
            }
            *cItem = (*lItem < *rItem ? *lItem : *rItem);
        }
    }
#if 0
    cout << "init phase1 success" << endl;
#endif
    return 0;
}
/**
 * @brief create and init sparse table
 * @param[in] arrayPtr ptr to the input array
 * @param[in] arrSize  tot nums of input
 *
 */
template<typename T>
ssize_t sparseTable<T>::createSt(const T *arrayPtr, const ssize_t arraySize){            
/*build st by input*/
    if(allocSt(arraySize)  < 0){
        cout << "alloc sparse table fail" << endl;
        return -1;
    }
    if(initSt(arrayPtr) < 0){
        destorySt();
        cout << "init sparse table fail" << endl;
        return -1;
    }
    return 0;
}

/**
 * @brief search the min num
 * @param[in] arrayPtr ptr to the input array
 * @param[in] arrSize  tot nums of input
 *
 */
template<typename T>
const T * sparseTable<T>::searchSt(const ssize_t startPos, ssize_t endPos){   
    ssize_t logPos;
    if(startPos < 0 || endPos < 0|| startPos >= *getMaxBase() || endPos >= *getMaxBase()|| startPos > endPos){
        return NULL;
    }
    logPos = stLog(endPos - startPos +  1);
    if(logPos < 0){
        return NULL;
    }
    T *lItem = getItem(startPos, logPos); 
    T *rItem = getItem(endPos - (1 << logPos) + 1, logPos);
    if(NULL == lItem || NULL == rItem){
        return NULL;
    }
    return (*lItem < *rItem ? lItem : rItem);
}
}//?end of sparse table?Sparse Table

int main()
{
    return 0;
}
