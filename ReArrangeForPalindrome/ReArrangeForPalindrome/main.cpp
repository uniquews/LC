//
//  main.cpp
//  ReArrangeForPalindrome
//
//  Created by Shuai Wang on 9/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    bool check1 (string str) {
        if (str.size() <= 1) {
            return true;
        }
        
        unordered_map<int, int> count;
        for (int i = 0; i < str.size(); i++) {
            count[str[i]]++;
        
        }
        
        int odd = 0;
        
        for (int i = 0; i < count.size(); i++) {
            if (count[str[i]] & 1) {
                odd++;
            }
        }
        
        if (odd > 1) {
            return false;
        } else {
            return true;
        }
    
    }


};

int main(int argc, const char * argv[])
{

    string str = "geeksforgeeks";
    string str2 = "geeksogeeks";
    
    Solution su;
    cout << su.check1(str) << endl;
    
    cout << su.check1(str2) << endl;
    return 0;
}

