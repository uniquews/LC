//
//  main.cpp
//  MinStack
//
//  Created by Shuai Wang on 4/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <utility>


#include <utility>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    void push(int x) {
        stk.push(x);
        if (minStk.size() == 0 || minStk.top() > x) {
            minStk.push(x);
        }
        return;
    }
    
    void pop() {
        if (stk.size() == 0) {
            return;
        }
        
        int tmp = stk.top();
        if (tmp == minStk.top()) {
            stk.pop();
            minStk.pop();
        } else {
            stk.pop();
        }
        return;
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};




int main(int argc, const char * argv[])
{

    // insert code here...Ω
    
    MinStack minStack;
    minStack.push(0);
    minStack.push(1);
    minStack.push(0);
    minStack.getMin();
    minStack.pop();
    minStack.getMin();
    
    
//    while (minStack.size() != 0) {
//        cout <<"The top is "<< minStack.top()<<" ";
//        cout<< "The min of the stack now is " << minStack.MinTop()<<" " << endl;
//        minStack.pop();
//    }
    

    
    return 0;
}

