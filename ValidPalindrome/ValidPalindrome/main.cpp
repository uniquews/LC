//
//  main.cpp
//  ValidPalindrome
//
//  Created by Shuai Wang on 3/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        
        int start = 0;
        int end = (int)s.size() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (start <= end) {
            while (start <= end && ::isalnum(s[start]) == 0) {
                start++;
            }
            
            while (start <= end && ::isalnum(s[end]) == 0) {
                end--;
            }
            
            if (start <= end && s[start] != s[end]) {
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
        
    }
    
};


int main(int argc, const char * argv[])
{

    // insert code here...
    string s="A man, a plan, a canal: Panama";
    bool result = Solution::isPalindrome(s);
    std::cout << result<< endl;
    return 0;
}

