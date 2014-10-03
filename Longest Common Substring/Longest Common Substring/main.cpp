//
//  main.cpp
//  Longest Common Substring
//
//  Created by Shuai Wang on 10/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
    int lcs(string &s1, string &s2) {
        if (s1.length() == 0 || s2.length() == 0) {
            return 0;
        }
        
        int m = (int)s1.length();
        int n = (int)s2.length();
        
        vector<vector<int>> f(m + 1, vector<int> (n + 1, 0));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            f[0][i] = 0;
        }
        
        for (int i = 1; i <= m; i++) {
            f[i][0] = 0;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j],f[i][j - 1]);
                }
            
            }
        }
        
        return f[m][n];
    
    }


};

int main(int argc, const char * argv[])
{

    string s1 = "ABCD";
    string s2 = "ABCD";
    Solution su;
    cout << su.lcs(s1, s2) <<endl;
    return 0;
}

