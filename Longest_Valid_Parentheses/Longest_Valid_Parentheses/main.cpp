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

//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        stack<int> stk; // keep track of the positions of non-matching '('s
//        int maxLength = 0; int last = -1; // the postion of the last ")"
//        
//        for(int i=0; i<s.length(); i++){
//            if(s[i] == '('){
//                stk.push(i);
//            }else{
//                if(stk.empty()){
//                    last = i;
//                }else{
//                    stk.pop();
//                    if(stk.empty()){
//                        maxLength = max(maxLength, i-last);
//                    }else{
//                        maxLength = max(maxLength, i-stk.top());
//                    }
//                }
//            }
//        }
//        
//        return maxLength;
//    }
//};

//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        int last = -1;
//        stack<int> stk;
//        int result = 0;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] == '(') {
//                stk.push(i);
//            } else {
//                if (stk.size() == 0 || s[stk.top()] != '(') {
//                    stk.push(i);
//                    last = i;
//                } else {
//                    stk.pop();
//                    if (stk.size() != 0) {
//                        result = max(result, i - stk.top());
//                    } else {
//                        result = max(result, i - last);
//                    }
//                }
//            }
//        }
//        
//        return result;
//    }
//};

class Solution {
public:
    int longestValidParentheses(string s) {
        int last = -1;
        stack<int> stk;
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (stk.size() == 0) {
                    last = i;
                } else if (s[stk.top()] == '(') {
                    stk.pop();
                    if (stk.size() == 0) {
                        result = max(i - last, result);
                    } else {
                        if (s[stk.top()] == '(') {
                            result = max(i - stk.top(), result);
                        } else {
                            result = max(i - last, result);
                        }
                    }
                }
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[])
{

//    string input = ")()())";
//    string input = "((()()))";
    string input = "(()";
    Solution su;
    cout << su.longestValidParentheses(input)<< endl;
    return 0;
}

