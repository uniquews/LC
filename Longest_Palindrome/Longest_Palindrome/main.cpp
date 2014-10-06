//
//  main.cpp
//  Longest_Palindrome
//
//  Created by Shuai Wang on 7/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) {
            return "";
        }
        
        int n = (int)s.size();
        
        vector<vector<bool>> isPP (n, vector<bool> (n, false));
        for (int i = 0; i < n; i++) {
            isPP[i][i] = true;
        }
        
        int maxLen = 1;
        int start = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPP[i + 1][j - 1])) {
                    isPP[i][j] = true;
                    maxLen = max(maxLen, j - i + 1);
                    start = i;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
    
};

int main(int argc, const char * argv[])
{
    
    string s="aaaa";
    Solution su;
    cout << su.longestPalindrome(s)<< endl;
    return 0;
}

