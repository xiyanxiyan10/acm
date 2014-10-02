/*
 * @brief   两个栈构建队列模板
 * @file    stacktoqueue.cpp
 * @author xiyanxiyan10
 * @CreatedTime 2014/10/02
 * @LastChanged 2014/10/02
 */


#include <stack>
#include <iostream>
#include <cstdio>

using namespace std;

class Squeue{
public:
    Squeue(void)  { squeueDestory(); }
    ~Squeue(void) { squeueDestory(); }
    void push(const int &val){
        stackMaster.push(val);
    }
    int pop(void){
        int val;
        if(stackServant.empty()){
            servantCharge();
        }
        if(stackServant.empty()){
             return -1;
        }
        val = stackServant.top();
        stackServant.pop();
        return val;
    }
private:
    void servantCharge(void){
        while(!stackMaster.empty()){
                int val;
                val = stackMaster.top();
                stackServant.push(val);
                stackMaster.pop();
        }
    }
    void squeueDestory(void){
        while(!stackServant.empty()){
            stackServant.pop();
        }
        while(!stackMaster.empty()){
            stackMaster.pop();
        }
    }
    stack<int> stackMaster;
    stack<int> stackServant;
};

#define PUSH "PUSH"
#define POP  "POP"

int main(int argc, char *argv[]){
    string action;
    int val;
    int actionCnt;
    int actionTot;
    class Squeue sq;

    cin >> actionTot;
    for(actionCnt = 1; actionCnt <= actionTot; actionCnt++){
        cin >> action;
        if(action == PUSH){
                cin >> val;
                sq.push(val);
        }else if(action == POP){
                cout << sq.pop() << endl;
        }else{
                cout << "assert" << endl;
                return -1;
        }
    }
    return 0;
}

