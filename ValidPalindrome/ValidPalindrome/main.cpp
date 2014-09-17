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
    bool isPalindrome(string s) {
        int start = 0;
        int end =s.size() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (start <= end) {
            if (::isalnum(s[start]) == 0) {
                start++;
                continue;
            }
            
            if (::isalnum(s[end]) == 0) {
                end--;
                continue;
            }
            
            if (s[start] == s[end]) {
                start++;
                end--;
            } else {
                return false;
            }
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

