/*
 * @brief  位图排序模版
 * @file bitSort.h
 * @author xiyanxiyan10
 * @CreatedTime 2014/09/04
 * @LastChanged 2014/10/02
 * @note 适用于数据大小中等，数据量较大但数据不重复
 *
 */
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
 
namespace fileSort{
class bmpSort{
public:
        bmpSort(const unsigned int &valMax){
            bmpAlloc(valMax);
        }
        void bmpSet(const unsigned int val){
            if(val >= blen)
                return;
            bmp[val >> 5] |= 1 << (0x1f & val);
        }
        ~bmpSort(void) {
            bmpDestory();
        }
        friend std::ifstream& operator >> (std::ifstream&, bmpSort&);
        friend std::ofstream& operator << (std::ofstream&, bmpSort&);
private:
        void bmpAlloc(const unsigned int &len){
            arrayPosMax = (len >> 5) + (len & 0x1f ? 1 : 0);
            bitPosMax   = 33;
            bmp = new unsigned int[arrayPosMax];
            blen = len;
        }
        void bmpDestory(void){
            if(bmp)
                delete bmp;
        }
        void initSearch(void){
                arrayPos = 0;
                bitPos  = 0;
        }
        int nextVal(unsigned int &val){
            if(bitPos >= bitPosMax){
                    arrayPos++;
                    bitPos = 0;
            }
            if(arrayPos >= arrayPosMax)
                    return -1;
            if(0 == bmp[arrayPos])
                    bitPos = 0;
            while(0 == bmp[arrayPos] && arrayPos < arrayPosMax)
                    arrayPos++;
            if(arrayPos >= arrayPosMax)
                    return -1;
            while( 0 == (bmp[arrayPos] & (1 << bitPos)) ){
                    bitPos++;
            }
            if( bitPos >= bitPosMax)
                return -1;
            val = (arrayPos << 5) + bitPos;
            bmp[arrayPos] &= ~(1 << bitPos);
            bitPos++;
            return 0;
        }
        int arrayPos;
        int arrayPosMax;
        int bitPos;
        int bitPosMax;
        unsigned int * bmp;
        unsigned int blen;
};
 
std::ifstream& operator >> (std::ifstream& in, bmpSort& bs){
    int val;
    while(in >> val){
        bs.bmpSet(val);
    }
    return in;
}
 
std::ofstream& operator << (std::ofstream& out, bmpSort& bs){
    unsigned int val;
    bs.initSearch();
    while( 0 == bs.nextVal(val)){
            out << val << "\n";
            if(out.fail())
                return out;
    }
    out << std::endl;
    return out;
}
 
};
 
using namespace std;
using namespace fileSort;
 
int main(int argc, char *argv[])
{
    unsigned int maxVal;
    if(4 != argc){
        return -1;
    }
    ifstream in;
    ofstream out;
 
    maxVal = (unsigned int)atoll(argv[1]);
 
    in.open(argv[2], ios::in);
    if(in.fail()){
        return -1;
    }
    out.open(argv[3], ios::out);
    if(out.fail()){
        return -1;
    }
    bmpSort bs(maxVal);
    in >> bs;
    out << bs;
    return 0;
}
