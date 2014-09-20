//
//  main.cpp
//  Palindrome Number
//
//  Created by Shuai Wang on 5/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        if (x < 10) {
            return true;
        }
        
        int tmp = x;
        int division = 1;
        while (tmp / division >= 10) {
            division *= 10;
            
        }
        
        while (x > 0) {
            int begin = x /division;
            int end = x % 10;
            if (begin != end) {
                return false;
            }
            x = x % division / 10;
            division = division / 100;
            
        }
        
        return true;
        
    }
    
};
int main(int argc, const char * argv[])
{

    // insert code here...
    Solution *s = new Solution();
    cout<< s->isPalindrome(1001)<< endl;
    return 0;
}

