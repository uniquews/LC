//
//  main.cpp
//  Interleaving_String
//
//  Created by Shuai Wang on 6/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s1.size() == 0 && s2.size() == 0 && s3.size() == 0) {
            return true;
        }
        
        if (s3.length() != s1.length() + s2.length())
            return false;
        
        vector<vector<bool>> f(s1.size() + 1, vector<bool> (s2.size() + 1));
        f[0][0] = true;
        
        for (int i = 1; i <= s2.size(); i++) {
            f[0][i] = (s2[i - 1] == s3[i - 1]) && f[0][i - 1];
        }
        
        for (int i = 1; i <= s1.size(); i++) {
            f[i][0] = (s1[i - 1] == s3[i - 1]) && f[i - 1][0];
        }
        
        
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                f[i][j] = ((s1[i - 1] == s3[i + j - 1]) && f[i - 1][j]) || ((s2[j - 1] == s3[i + j - 1]) && f[i][j - 1]);
            }
        }
        
        return f[s1.size()][s2.size()];
    }
    
};

int main(int , const char * argv[])
{

    string s1="a";
    string s2 = "b";
    string s3 = "ab";
    
    Solution s;
    cout << s.isInterleave(s1, s2, s3);
    return 0;
}

