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
        char *endptr;
        strtod(s, &endptr);
        
        if(s == endptr) return false;
        
        for(; *endptr; endptr++){
            if(!isspace(*endptr)) return false;
        }
        
        return true;
    }
};

int main(int argc, const char * argv[])
{

    char a = '3';
    char *s = &a;
    Solution su;
    std::cout << su.isNumber(s);
    
    return 0;
}

