//
//  main.cpp
//  ValidParentheses
//
//  Created by Shuai Wang on 3/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        if (s.size() == 0) {
            return false;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else {
                if (stk.size() == 0) {
                    return false;
                }
                
                if (s[i] == '}' && stk.top() == '{') {
                    stk.pop();
                } else if (s[i] == ')' && stk.top() == '(') {
                    stk.pop();
                } else if (s[i] == ']' && stk.top() == '[') {
                    stk.pop();
                }
            }

        }
        
        
                    
        if (stk.size() != 0) {
            return false;
        } else {
            return true;
        }
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    vector<char> input={'[','}'};

    bool result = Solution::Valid(input);
    std::cout << result<< endl;
    return 0;
}

