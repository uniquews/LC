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
        
        int division = 1;
        while (x / division >= 10) {
            division *= 10;
        }
        
        while (x > 0) {
            int start = x / division;
            int end = x % 10;
            if (start != end) {
                return false;
            }
            
            x = x % division;
            x = x / 10;
            division = division / 100;
        }
        
        return true;
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
    Solution *s = new Solution();
    cout<< s->isPalindrome(111111)<< endl;
    return 0;
}

