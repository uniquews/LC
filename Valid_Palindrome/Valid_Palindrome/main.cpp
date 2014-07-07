//
//  main.cpp
//  Valid_Palindrome
//
//  Created by Shuai Wang on 7/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto start  = s.begin();
        auto end = prev(s.end());
        
        while(start <end){
            if(!std::isalnum(*start)){
                start++;
                continue;
            }
            if(!std::isalnum(*end)){
                end--;
                continue;
            }
            
            if(*start == *end){
                start++;
                end--;
            }else{
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

