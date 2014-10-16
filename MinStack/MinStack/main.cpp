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
    stack<pair<int, int>> stk;
    int _min = 2147483647;
    MinStack() {
        // do initialization if necessary
         
        
    }

    void push(int number) {
        // write your code here
        if (stk.size() == 0) {
            _min = number;
            stk.push(make_pair(number, number));
        } else {
            if (number < stk.top().second) {
                stk.push(make_pair(number, number));
            } else {
                stk.push(make_pair(number, stk.top().second));
            }
            
        }
    }

    int pop() {
        // write your code here
        int result = stk.top().first;
        stk.pop();
        return result;
    }

    int min() {
        // write your code here
        return stk.top().second;
    }
};




int main(int argc, const char * argv[])
{

    // insert code here...Ω
    
    MinStack minStack(new stack<pair<int,int>>());
    minStack.push(4);
    minStack.push(5);
    minStack.push(8);
    
    
    while (minStack.size() != 0) {
        cout <<"The top is "<< minStack.top()<<" ";
        cout<< "The min of the stack now is " << minStack.MinTop()<<" " << endl;
        minStack.pop();
    }
    

    
    return 0;
}

