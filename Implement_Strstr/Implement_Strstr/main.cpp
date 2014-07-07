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
        if(haystack==NULL|| needle==NULL)
            return NULL;
        int hlength = strlen(haystack);
        int nlength = strlen(needle);
        
        if(nlength > hlength)
            return NULL;
        
        for(int i=0; i< hlength-nlength+1; i++){
            int j=0;
            char *p =&haystack[i];
            for(; j< nlength; j++){
                if(*p != needle[j]){
                    break;
                }
                p++;
            }
            
            if(j == nlength){
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

