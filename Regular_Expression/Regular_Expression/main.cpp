//
//  main.cpp
//  Regular_Expression
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') {
            return *s == '\0';
        }
        
        if (*(p + 1) != '*') {
            if ((*p == *s) || (*p == '.' && *s != '\0')) {
                return isMatch(s + 1, p + 1);
            } else {
                return false;
            }
        } else {
            while ((*p == *s) || (*p == '.' && *s != '\0')) {
                if (isMatch(s, p + 2)) {
                    return true;
                }
                
                s++;  // "ccccccca, c*a"
            }
            
            return isMatch(s, p + 2);  // isMatch("aab", "c*a*b") → true
        }
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

