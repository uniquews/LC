//
//  main.cpp
//  Longest_Valid_Parentheses
//
//  Created by Shuai Wang on 7/9/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk; // keep track of the positions of non-matching '('s
        int maxLength = 0; int last = -1; // the postion of the last ")"
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                stk.push(i);
            }else{
                if(stk.empty()){
                    last = i;
                }else{
                    stk.pop();
                    if(stk.empty()){
                        maxLength = max(maxLength, i-last);
                    }else{
                        maxLength = max(maxLength, i-stk.top());
                    }
                }
            }
        }
        
        return maxLength;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

