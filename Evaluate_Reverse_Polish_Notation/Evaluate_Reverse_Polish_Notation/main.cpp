//
//  main.cpp
//  Evaluate_Reverse_Polish_Notation
//
//  Created by Shuai Wang on 7/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        
        for(int i=0; i<tokens.size(); i++){
            if((tokens[i][0] == '-' && tokens[i].size()>1) ||
               (tokens[i][0] >='0' && tokens[i][0] <='9')){
                stk.push(atoi(tokens[i].c_str()));
                continue;
            }
            
            int op1 = stk.top();
            stk.pop();
            int op2 = stk.top();
            stk.pop();
            
            if(tokens[i] == "+") stk.push(op1+op2);
            if(tokens[i] == "-") stk.push(op2 - op1);
            if(tokens[i] == "*") stk.push(op1 * op2);
            if(tokens[i] == "/") stk.push(op2/op1);
        }
        
        return stk.top();
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

