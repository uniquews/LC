//
//  main.cpp
//  Implement_Strstr
//
//  Created by Shuai Wang on 7/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        
        
        if (haystack == nullptr || needle == nullptr) {
            return NULL;
        }
        
        int hayLength = strlen(haystack);
        int needleLength = strlen(needle);
        
        int i = 0;
        int j = 0;
        
        for (; i < hayLength - needleLength + 1; i++) {
            for (; j < needleLength; j++) {
                if (haystack[i + j] != needle[j]) {
                    j = 0;
                    break;
                }
            }
            
            if (j == needleLength) {
                return &haystack[i];
            }
        }
        
        return NULL;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

