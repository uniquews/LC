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
            return nullptr;
        }
        
        int hayLen = strlen(haystack);
        int neeLen = strlen(needle);
        
        if (neeLen > hayLen) {
            return nullptr;
        }
        
        for (int i = 0; i <= hayLen - neeLen; i++) {
            int j = 0;
            while (j < neeLen && haystack[i + j] == needle[j]) {
                j++;
            }
            
            if (j == neeLen) {
                return &haystack[i];
            }
        }
        
        return nullptr;
        
    }
};
int main(int argc, const char * argv[])
{

    char *haystack = "mississippi";
    char *needle = "issipi";
    
    Solution su;
    su.strStr(haystack, needle);
    
    
    return 0;
}

