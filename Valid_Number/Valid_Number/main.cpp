//
//  main.cpp
//  Valid_Number
//
//  Created by Shuai Wang on 7/8/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isNumber(const char *s) {
        int start = 0;
        int end = (int)strlen(s) - 1;
        while (start <= end && s[start] == ' ') {
            start++;
        }
        
        if (start > end) {
            return false;
        }
        
        while (end >= start && s[end] == ' ') {
            end--;
        }
        
        if (s[start] == '+' || s[start] == '-') {
            start++;
        }
        
        bool num = false;
        bool exp = false;
        bool dot = false;
        while (start <= end) {
            if (s[start] >= '0' && s[start] <= '9') {
                num = true;
            } else if (s[start] == 'e') {
                if (exp || (num == false)) {
                    return false;
                }
                exp = true;
                num = false;
            } else if (s[start] == '.') {
                if (exp || dot) {
                    return false;
                }
                dot = true;
            } else if (s[start] == '+' || s[start] == '-') {
                if (s[start - 1] != 'e') {
                    return false;
                }
            } else {
                return false;
            }
            start++;
            
        }
        
        return num;
    }
};

int main(int argc, const char * argv[])
{

//    char *s = "3";
    char *s = "32.e-80123";
    Solution su;
    std::cout << su.isNumber(s);
    
    return 0;
}

