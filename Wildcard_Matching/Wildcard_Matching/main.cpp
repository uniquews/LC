//
//  main.cpp
//  Wildcard_Matching
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

//递归解法
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        
        if (*s == '\0') {
            while(*p == '*') {
                p++;
            }
            return *p == '\0';
        }
        
        if (*p == '\0') {
            return false;
        }
        
        while (*s && *p) {
            if (*s != *p) {
                if (*p == '?') {
                    s++, p++;
                } else if (*p == '*') {
                    
                    while(*p == '*') {
                        p++;//跳过连续的*号
                    }
                    
                    if (*p == '\0') {
                        return true;//如果跳过*号就到达结尾，那么是匹配的
                    }
                    
                    while (*s) {
                        if (isMatch(s, p)) {
                            return true;//不停的尝试
                        }
                        
                        s++;
                    }
                } else {
                    return false;
                }
            } else {
                s++, p++;
            }
        }
        return isMatch(s, p);
    }
};

int main(int argc, const char * argv[])
{

    char *s = "aa";
    char *p = "?*?";
    
    Solution su;
    cout << su.isMatch(s, p) << endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

