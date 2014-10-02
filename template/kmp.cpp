/*
 * @brief  kmp模板
 * @file kmp.cpp
 * @author xiyanxiyan10
 * @CreatedTime 2014/10/02
 * @LastChanged 2014/10/02
 */

#include<iostream>
#include<string>
#include<cstring>

namespace patternMatch{
using namespace std;

typedef unsigned int size_t;
typedef signed   int ssize_t;

class kmp{
public:
    kmp(void){ destoryPattern();}
    virtual ~kmp(void){ destoryPattern();}
    virtual void debug(void);
    ssize_t createPattern(const string &patternStr);
    ssize_t matchPos(const string &targetStr);
private:
    inline const char   getPattern(const ssize_t &pos) const { return pattern[pos];}
    inline const ssize_t getNext(const ssize_t &pos) const { return next[pos]; }
    inline void setNext(const ssize_t &pos, const ssize_t &val) { next[pos] = val;}
    inline const ssize_t getPatternLen(void) const { return patternSize; }
    ssize_t allocPattern(const string &patternStr);
    void initPatern(void);
    void destoryPattern(void);
    string pattern;
    ssize_t patternSize;
    ssize_t *next;
};

void kmp::destoryPattern(void){
    patternSize = 0;
    pattern.clear();
    if(next){
            delete next;
    }
}

ssize_t kmp::allocPattern(const string &patternStr){
    pattern = patternStr;
    patternSize = pattern.size();
    next = new ssize_t[patternSize];
    if(!next){
        return -1;
    }
    memset(next, 0, patternSize);
    return 0;
}

void kmp::initPatern(void){
    next[0] = 0;
    for(ssize_t pos = 1, matchLen = 0; pos < getPatternLen(); pos++){
            while( (getPattern(matchLen) != getPattern(pos)) && matchLen != 0)
                        matchLen = getNext(matchLen - 1);
            if(getPattern(matchLen) == getPattern(pos))
                        matchLen++;
            setNext(pos, matchLen);
    }
}

ssize_t kmp::createPattern(const string &patternStr){
        if(allocPattern(patternStr) < 0){
                return -1;
        }
        initPatern();
        return 0;
}

ssize_t kmp::matchPos(const string &targetStr){
    ssize_t pos = 0;
    ssize_t targetLen = targetStr.size();
    if(!targetLen || targetLen < getPatternLen()){
            return -1;
    }
    while(pos <= targetLen - getPatternLen()){
            ssize_t matchLen = 0;
            while( (targetStr[pos + matchLen] == getPattern(matchLen)) && (matchLen < getPatternLen()) ){
                    ++matchLen;
            }
            if(matchLen == getPatternLen()){
                    return pos;
            }
            if(!matchLen){
                pos++;
            }else{
                pos = pos + (matchLen - getNext(matchLen - 1));
            }
    }
    return -1;
}

void kmp::debug(){
    cout << "pattern str = " << pattern << endl;
    cout << "pattern len = " << getPatternLen() << endl;
    cout << "next array  = ";
    for(ssize_t pos = 0; pos < getPatternLen(); pos++){
            cout << getNext(pos) << " ";
    }
    cout << endl;
}

}/*end of pattern match*/

using namespace patternMatch;

int main()
{
    string patternStr;
    string targetStr;
    class kmp *kp = new class kmp;
    if(!kp){
        cout << "new kmp fail" << endl;
        return -1;
    }
    cout << "input pattern string" << endl;
    cin >> patternStr;
    if(kp->createPattern(patternStr) < 0){
        cout << "create pattern string fail" << endl;
    }
    kp->debug();
    cout << "input targert string" << endl;
    while(cin >> targetStr){
            ssize_t pos = kp->matchPos(targetStr);
            cout << "match pos: ";
            if(pos == -1){
                    cout << "fail";
            }else{
                    cout << pos;
            }
            cout << endl;
            cout << "input targert string" << endl;
    }
    return 0;
}

