//
//  main.cpp
//  Evaluate Reverse Polish Notation
//
//  Created by Shuai Wang on 9/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

#include <string>

#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if ((tokens[i][0] >= '0' && tokens[i][0] <= '9') ||
                (tokens[i][0] == '-' && tokens[i].size() > 1)) {
                stk.push(stoi(tokens[i]));
            } else {
                int num1 = stk.top();
                stk.pop();
                if (stk.size() == 0) {
                    return num1;
                }
                int num2 = stk.top();
                stk.pop();
                int result = 0;
                if (tokens[i] == "+") {
                    result = num1 + num2;
                } else if (tokens[i] == "-") {
                    result = num2 - num1;
                } else if (tokens[i] == "*") {
                    result = num2 * num1;
                } else {
                    result = num2 / num1;
                }
                
                stk.push(result);
            }
        }
        
        return stk.top();
    }
};

int main(int argc, const char * argv[])
{

    vector<string> tokens = {"-1","1","*","-1","+"};
    Solution su;
    cout << su.evalRPN(tokens) << endl;
    return 0;
}

