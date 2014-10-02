/*
 * @brief  fabonacci模板
 * @file huffman1.cpp
 * @author xiyan
 * @CreatedTime 2014/10/02
 * @LastChanged 2014/10/02
 * @note 求fabonacci数列的第n项
 */



#include <iostream>
using namespace std;
 
 
class Fibonacci{
    public:
            Fibonacci(void):first(0), second(1){}
            int getElement(const int &n);
    private:
            const int first;
            const int second;
};
 
int Fibonacci::getElement(const int &n){
    if(0 == n)
        return first;
    if(1 == n)
        return second;
    int prev   = prev;
    int curr   = second;
    int cnt  = n - 1;
    while(cnt--){
            int record = curr;
            curr = prev + record;
            prev = record;
    }
    return curr;
}

int main()
{
    return 0;
}
